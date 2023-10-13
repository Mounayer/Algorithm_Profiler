# Algorithm Profiler

This is an algorithm profiler made using C++17, using [gnuplot](http://www.gnuplot.info/) and [matplotplusplus](https://github.com/alandefreitas/matplotplusplus).

## How to run

    - Make sure use have C++ 17
    - Install matplotplusplus using vckpg or any other package manager
    - Install gnuplot and make sure to add it to the system's PATH environment variable
    - Modify data size if you wish or add new algorithms, then run

## Purpose

This program has a very simple functionality. It times a sorting algorithm against various data sizes and other algorithms, graphs it, then saves the results to disk in markdown format.

## All Results

If you would like to see the results of QuickSort, MergeSort, BubbleSort, SelectionSort, and InsertionSort when run on my system, you can do so here: [All Results](https://github.com/Mounayer/Algorithm_Profiler/blob/main/Algorithm%20Profiler/AllResults.md)

## Fastest Sort For Each Data Size

If you would like to see the results of the fastest Sorting algorithm for each of the data sizes I tested on my system, you can do so here: [Fastest Algorithms For Each Data Size](https://github.com/Mounayer/Algorithm_Profiler/blob/main/Algorithm%20Profiler/Fastest.md)

## Graphing

This program uses [gnuplot](http://www.gnuplot.info/) and [matplotplusplus](https://github.com/alandefreitas/matplotplusplus) to graph the performance (time vs data size) for each of the Profiled Algorithms

### Bubble Sort

![Alt text](<Algorithm Profiler/Bubble Sort.png>)

### Selection Sort

![Alt text](<Algorithm Profiler/Selection Sort.png>)

### Insertion Sort

![Alt text](<Algorithm Profiler/Insertion Sort.png>)

### Merge Sort

![Alt text](<Algorithm Profiler/Merge Sort.png>)

### Quick Sort

![Alt text](<Algorithm Profiler/Quick Sort.png>)
