//
// Created by Yory on 2019/1/5.
//


/*
 * Priority queue
 *
 *
 * */

#ifndef SORTINGALGORITHMS_MAXHEAPSLOW_H
#define SORTINGALGORITHMS_MAXHEAPSLOW_H


#include<cassert>
#include "../util/ArrayHelper.h"

template <typename T>
class PriorityQueue {
public:
    void test();
    void HeapSort1(T* arr, int n);
    void HeapSort2(T* arr, int n);

    PriorityQueue(int capacity = 100);
    PriorityQueue(T *arr, int n);
    ~PriorityQueue();

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
void PriorityQueue<T>::test() {
    int n = 20;
    srand(time(NULL));
    PriorityQueue<T> queue = PriorityQueue<T>(n);
    for (int i = 0; i < n; ++i) {
        int temp = rand() % n;
        cout<<temp<<' ';
        queue.Insert(temp);
    }
    cout<<endl;

    while (!queue.IsEmpty()){
        cout<<queue.ExtractMax()<<' ';
    }
    cout<<endl;
}

template <typename T>
void PriorityQueue<T>::HeapSort1(T *arr, int n) {
    PriorityQueue<T> maxHeap = PriorityQueue<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.Insert(arr[i]);
    }

    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
void PriorityQueue<T>::HeapSort2(T *arr, int n) {
    PriorityQueue<T> maxHeap = PriorityQueue<T>(arr, n);
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue(int capacity): capacity(capacity) {
    currentSize = 0;
    arr = new T[capacity + 1];
}

template <typename T>
PriorityQueue<T>::PriorityQueue(T *arr, int n): capacity(n) {
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
PriorityQueue<T>::~PriorityQueue() {
    delete[] arr;
}

template <typename T>
void PriorityQueue<T>::Insert(T item) {
    assert(currentSize + 1 <= capacity);

    arr[++currentSize] = item;
    ShiftUp(currentSize);
}

template <typename T>
void PriorityQueue<T>::ShiftUp(int k) {
    while (k > 1 && arr[k/2] < arr[k]){
        swap(arr[k], arr[k/2]);
        k /= 2;
    }
}

template <typename T>
T PriorityQueue<T>::ExtractMax() {
    assert(currentSize != 0);
    T res = arr[1];
    arr[1] = arr[currentSize--];
    ShiftDown(1);
    return res;
}

template <typename T>
bool PriorityQueue<T>::IsEmpty() {
    return currentSize == 0;
}

template <typename T>
void PriorityQueue<T>::ShiftDown(int k) {
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
