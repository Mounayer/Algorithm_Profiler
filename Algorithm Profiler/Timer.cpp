#include <chrono>
#include "Timer.h"

std::chrono::time_point<std::chrono::high_resolution_clock> Timer::start_time;


void Timer::start()
{
    start_time = std::chrono::high_resolution_clock::now();
}

double Timer::end()
{
    auto end_time = std::chrono::high_resolution_clock::now();
    auto elapsed = end_time - start_time;
    double seconds = std::chrono::duration<double>(elapsed).count();
    return seconds;
}
