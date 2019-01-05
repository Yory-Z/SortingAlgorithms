//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_SELECT_H
#define SORTINGALGORITHMS_SELECT_H

#include "../util/ArrayHelper.h"
using namespace ArrayHelper;

template <class T>
class Select {
public:
    void testSelectionSort();
    static void SelectionSort(T* arr, int n);
};

template <class T>
void Select<T>::testSelectionSort() {
    int n = 10;
    int *arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    ArrayHelper::PrintArray(arr, n);
    SelectionSort(arr, n);
    ArrayHelper::PrintArray(arr, n);
}

template <class T>
void Select<T>::SelectionSort(T *arr, int n) {
    for (int i = 0; i < n; ++i) {
        //find the minimum element's index
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[minIndex] > arr[j]){
                minIndex = j;
            }
        }
        //if the minimum index minIndex is not the first index i
        //then swap then
        if (minIndex != i){
            swap(arr[i], arr[minIndex]);
        }
    }
}

#endif //SORTINGALGORITHMS_SELECT_H
