#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include <vector>

template <typename T>
void selectionSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; ++i) {

        int min_idx = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        T temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
};



#endif