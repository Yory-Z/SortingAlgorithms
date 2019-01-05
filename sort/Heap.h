//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_HEAP_H
#define SORTINGALGORITHMS_HEAP_H


#include "../util/ArrayHelper.h"

template <class T>
class Heap {
public:
    void testHeapSort();
    static void HeapSort(T *arr, int n);

private:
    static void ShiftDown(T *arr, int k, int n);
};

template <class T>
void Heap<T>::testHeapSort() {
    int n = 20;
    int *arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    ArrayHelper::PrintArray(arr, n);
    HeapSort(arr, n);
    ArrayHelper::PrintArray(arr, n);

}

template <class T>
void Heap<T>::HeapSort(T *arr, int n) {
    //initializing the max heap
    for (int i = (n - 1)/2; i >= 0; --i) {
        ShiftDown(arr, i, n);
    }

    //sorting the max heap
    for (int j = n - 1; j > 0; --j) {
        swap(arr[0], arr[j]);
        ShiftDown(arr, 0, j);
    }
}

template <class T>
void Heap<T>::ShiftDown(T *arr, int k, int n) {
    while (2 * k + 1 < n){
        int j = 2 * k + 1;
        if (j + 1 < n && arr[j + 1] > arr[j]){
            ++j;
        }

        //when the k's child's value is smaller than itself, stop shifting
        if (arr[k] >= arr[j]){
            break;
        }

        swap(arr[k], arr[j]);
        k = j;
    }
}

#endif //SORTINGALGORITHMS_HEAP_H
