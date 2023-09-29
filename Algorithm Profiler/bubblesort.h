#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include <vector>

template <typename T>
void bubbleSort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());
    bool swapped;
    for (int i = 0; i < n - 1; ++i) {

        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        
        if (!swapped)
            break;
    }
};



#endif