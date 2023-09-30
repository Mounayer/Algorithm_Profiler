#ifndef PROFILER_H
#define PROFILER_H
#include <vector>
#include <string>
#include <functional>
#include <iostream>
#include <matplot/matplot.h>
#include <unordered_map>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include "Timer.h"

template <typename T>
class Profiler
{
private:

    std::vector<double> sizes;  // Store sizes of each vector
    std::vector<double> times;  // Store time taken for sorting each vector

    struct SortResult
    {
        std::string m_function_name{};
        double m_time{};

        SortResult() = default;
        SortResult(std::string name, double time) : m_function_name{ name }, m_time{ time } {}

        bool operator<(const SortResult& other) const {
            return m_time < other.m_time;
        }

        friend std::ostream& operator<<(std::ostream& os, const SortResult& sr) {
            os << sr.m_time << "s";
            return os;
        }
    };

    static std::unordered_map<int, std::vector<SortResult>> all_times;

public:

    /*
    Profiles the passed function using the data provided
    Graphs (time vs data size) and stores it as "filename.png"
    */
    Profiler(std::vector<std::vector<T>> vec,
        const std::function<void(std::vector<T>&)>& func,
        const std::string filename)
    {
        for (auto& inner_vec : vec)
        {
            sizes.push_back(static_cast<double>(inner_vec.size()));
            std::vector<T> copy = inner_vec;
            int one_size = static_cast<int>(copy.size());
            Timer::start();
            func(copy);
            double elapsed_time = Timer::end();
            all_times[one_size].push_back(SortResult(filename, elapsed_time));
            times.push_back(elapsed_time);
        }

        using namespace matplot;
        auto p = plot(sizes, times, "-o");
        title(filename);
        xlabel("Vector Size");
        ylabel("Time (seconds)");

        save(filename + ".png");

        std::cout << "Finished Profiling [" << filename << "]" << std::endl;
    }

    /*
    Displays the results
    Stores:
        1- All the results in AllResults.md
        2- The fastest performing algorithms for each data size in Fastest.md
    */
    static void displayAndSaveAllResults()
    {
        std::ofstream allResultsFile("AllResults.md");
        std::ofstream fastestFile("Fastest.md");

        std::vector<int> sorted_keys;
        for (const auto& pair : all_times)
            sorted_keys.push_back(pair.first);

        std::sort(sorted_keys.begin(), sorted_keys.end());

        if (allResultsFile.good())
        {
            // Print header
            std::string header = "| Size   |";
            std::string separator = "|--------|";

            if (!all_times.empty()) {

                auto headerResults = all_times.begin()->second;

                std::sort(headerResults.begin(), headerResults.end(), [](const SortResult& a, const SortResult& b) {
                    return a.m_function_name < b.m_function_name;
                    });

                for (const auto& sortResult : headerResults) {
                    header += " " + sortResult.m_function_name + " |";
                    separator += "--------------|";
                }
            }

            std::cout << header << std::endl;
            std::cout << separator << std::endl;

            allResultsFile << header << "\n";
            allResultsFile << separator << "\n";

            for (int size : sorted_keys)
            {
                std::vector<SortResult> results = all_times[size];

                std::sort(results.begin(), results.end(), [](const SortResult& a, const SortResult& b) {
                    return a.m_function_name < b.m_function_name;
                    });

                std::string line = "| " + std::to_string(size) + " |";
                for (const auto& sortResult : results) {
                    std::ostringstream streamObj;
                    streamObj << std::fixed << std::setprecision(10) << sortResult.m_time;
                    line += " " + streamObj.str() + "s |";
                }

                std::cout << line << std::endl;
                allResultsFile << line << "\n";
            }
        }

        if (fastestFile.good())
        {
            fastestFile << "| Size   | Fastest Algorithm | Time        |\n";
            fastestFile << "|--------|-------------------|-------------|\n";

            for (int size : sorted_keys)
            {
                std::vector<SortResult> results = all_times[size];

                // Sorting based on time to find the fastest.
                std::sort(results.begin(), results.end(), [](const SortResult& a, const SortResult& b) {
                    return a.m_time < b.m_time;
                    });

                // Using the first result since it's the fastest.
                std::ostringstream streamObj;
                streamObj << std::fixed << std::setprecision(10) << results[0].m_time;

                fastestFile << "| " << size << " | " << results[0].m_function_name << " | " << streamObj.str() << "s |\n";
            }
        }

        allResultsFile.close();
        fastestFile.close();
    }



};

template <typename T>
std::unordered_map<int, std::vector<typename Profiler<T>::SortResult>> Profiler<T>::all_times;

#endif
