#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <vector>

template <typename T>
void insertionSort(std::vector<T>& arr) {

    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; ++i) {

        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            
            arr[j + 1] = arr[j];
            j = j - 1;

        }
        arr[j + 1] = key;
    }
};



#endif
