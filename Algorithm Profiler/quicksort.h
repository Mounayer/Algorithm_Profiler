#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <vector>

template <typename T>
int partition(std::vector<T>& arr, int low, int high) {
    T pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;

            T temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    T temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}


template <typename T>
void quickSort(std::vector<T>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort<T>(arr, low, pi - 1);
        quickSort<T>(arr, pi + 1, high);
    }
}

template <typename T>
void quicksort(std::vector<T>& arr) {
    quickSort<T>(arr, 0, static_cast<int>(arr.size() - 1));
}

#endif
