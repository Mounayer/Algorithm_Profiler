#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <iostream>

class Timer {
private:
    static std::chrono::time_point<std::chrono::high_resolution_clock> start_time;

public:
    // Start the timer
    static void start();

    // End the timer and return the elapsed time in seconds
    static double end();
};


#endif