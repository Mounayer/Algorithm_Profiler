#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "bubblesort.h"
#include "insertionsort.h"
#include "selectionsort.h"
#include "Profiler.h"
#include "mergesort.h"
#include "quicksort.h"

using namespace std;

std::vector<std::vector<int>> generateTestData() {
    std::vector<std::vector<int>> data;

    // Some sizes chosen to demonstrate runtime complexity
    // These sizes include small vectors, medium vectors, and large vectors
    std::vector<int> sizes = {
        10, 16, 32, 50, 64, 80, 100, // Small
        250, 500, 750, 1000, 1250, 1500 , 1750, 2000, // Medium
        3000, 4000, 5000, 6000, 8000, 10000, // Large
        12000, 16000, 20000, 24000, 28000, 32000, // Very Large
        38000, 44000, 48000, 56000, 62000, 68000, 74000, 82000, // Gigantic
        90000, 100000, 120000, 150000, 200000 // Very Gigantic
    };

    // Seed for randomness
    std::random_device rd;
    std::mt19937 g(rd());

    for (int size : sizes) {

        // Create a vector with numbers from 0 to size-1
        std::vector<int> vec(size);
        std::iota(vec.begin(), vec.end(), 0);

        // Shuffle the vector to make it random
        std::shuffle(vec.begin(), vec.end(), g);

        data.push_back(vec);
    }

    return data;
}

int main() {

    auto testData = generateTestData();

    Profiler<int>(testData, bubbleSort<int>, "Bubble Sort");
    Profiler<int>(testData, insertionSort<int>, "Insertion Sort");
    Profiler<int>(testData, selectionSort<int>, "Selection Sort");
    Profiler<int>(testData, mergesort<int>, "Merge Sort");
    Profiler<int>(testData, quicksort<int>, "Quick Sort");
    // Simply call the Profiler constructor to profile a sorting algorithm with the data set.

    Profiler<int>::displayAndSaveAllResults();

}
