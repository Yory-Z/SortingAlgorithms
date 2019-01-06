//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_MAXHEAPSLOW_H
#define SORTINGALGORITHMS_MAXHEAPSLOW_H


#include<cassert>
#include "../util/ArrayHelper.h"

template <typename T>
class MaxHeapSlow {
public:
    static void HeapSort1(T *arr, int n);
    static void HeapSort2(T *arr, int n);

    explicit MaxHeapSlow(int capacity = 100);
    explicit MaxHeapSlow(T *arr, int n);
    ~MaxHeapSlow();

    void Insert(T item);
    T ExtractMax();
    bool IsEmpty();

private:
    int capacity;
    T* arr;
    int currentSize;
    void ShiftUp(int k);
    void ShiftDown(int k);
};

template <typename T>
void MaxHeapSlow<T>::HeapSort1(T *arr, int n) {
    MaxHeapSlow<T> maxHeap = MaxHeapSlow<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.Insert(arr[i]);
    }

    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
void MaxHeapSlow<T>::HeapSort2(T *arr, int n) {
    MaxHeapSlow<T> maxHeap = MaxHeapSlow<T>(arr, n);
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
MaxHeapSlow<T>::MaxHeapSlow(int capacity): capacity(capacity) {
    currentSize = 0;
    arr = new T[capacity + 1];
}

template <typename T>
MaxHeapSlow<T>::MaxHeapSlow(T *arr, int n): capacity(n) {
    this->arr = new T[capacity + 1];
    for (int i = 0; i < n; ++i) {
        this->arr[i+1] = arr[i];
    }
    currentSize = n;

    for (int i = n/2; i >= 1; --i) {
        ShiftDown(i);
    }
}

template <typename T>
MaxHeapSlow<T>::~MaxHeapSlow() {
    delete[] arr;
}

template <typename T>
void MaxHeapSlow<T>::Insert(T item) {
    assert(currentSize + 1 <= capacity);

    arr[++currentSize] = item;
    ShiftUp(currentSize);
}

template <typename T>
void MaxHeapSlow<T>::ShiftUp(int k) {
    while (k > 1 && arr[k/2] < arr[k]){
        swap(arr[k], arr[k/2]);
        k /= 2;
    }
}

template <typename T>
T MaxHeapSlow<T>::ExtractMax() {
    assert(currentSize != 0);
    T res = arr[1];
    arr[1] = arr[currentSize--];
    ShiftDown(1);
    return res;
}

template <typename T>
bool MaxHeapSlow<T>::IsEmpty() {
    return currentSize == 0;
}

template <typename T>
void MaxHeapSlow<T>::ShiftDown(int k) {
    while (k * 2 <= currentSize) {
        int j = 2 * k;
        if (j + 1 <= currentSize && arr[j] < arr[j + 1]) {
            ++j;
        }

        if (arr[k] >= arr[j]) {
            break;
        }

        swap(arr[k], arr[j]);
        k = j;
    }
}

#endif //SORTINGALGORITHMS_MAXHEAPSLOW_H
