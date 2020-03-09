//
// Created by Yory on 2019/1/6.
//

/*
 * Priority Queue Index
 * (This version just can insert in a time. it means you can not insert after extracting.
 * Because when inserting a elements, the index would override the existent elements's index)
 * Optimising the priority queue
 * If the element of priority queue, it will causing much time when shifting elements.
 * But in Priority queue index, we just need to shifting the index, not the elements.
 * */

#ifndef SORTINGALGORITHMS_HEAPINDEX_H
#define SORTINGALGORITHMS_HEAPINDEX_H

#include <cassert>
#include <ctime>
#include "../util/HeapHelper.h"

template <typename T>
class PriorityQueueIndex {
public:
    static void test();
    PriorityQueueIndex(int capacity = 100);
    ~PriorityQueueIndex();

    void Insert(T item);
    T ExtractMax();
    bool IsEmpty();

private:
    int capacity;
    int currentSize;
    T* arr;
    int* index;
    void ShiftDown(int k);
    void ShiftUp(int k);
};

template <typename T>
void PriorityQueueIndex<T>::test() {
    int n = 10;
    PriorityQueueIndex<T> queue = PriorityQueueIndex<T>(n);
    srand(time(NULL));
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
PriorityQueueIndex<T>::PriorityQueueIndex(int capacity): capacity(capacity), currentSize(0) {
    arr = new T[capacity];
    index = new int[capacity];
}

template <typename T>
PriorityQueueIndex<T>::~PriorityQueueIndex() {
    delete []arr;
    delete []index;
}

template <typename T>
void PriorityQueueIndex<T>::Insert(T item) {
    assert(currentSize < capacity);

    //this index may be existent
    index[currentSize] = currentSize;
    arr[currentSize] = item;
    ShiftUp(currentSize);
    ++currentSize;
}

template <typename T>
T PriorityQueueIndex<T>::ExtractMax() {
    assert(currentSize != 0);

    T max = arr[index[0]];
    arr[index[0]] = arr[index[--currentSize]];
    ShiftDown(0);
    return max;
}

template <typename T>
bool PriorityQueueIndex<T>::IsEmpty() {
    return currentSize == 0;
}

template <typename T>
void PriorityQueueIndex<T>::ShiftUp(int k) {
    T target = arr[index[k]];
    int tarIndex = index[k];

    while (k > 0 && arr[index[(k - 1) / 2]] < target){
        index[k] = index[(k - 1) / 2];
        k = (k - 1) / 2;
    }
    index[k] = tarIndex;
}

template <typename T>
void PriorityQueueIndex<T>::ShiftDown(int k) {
    T target = arr[index[k]];
    int tarIndex = index[k];

    while (k * 2 + 1 < currentSize){
        int j = k * 2 + 1;
        if (j + 1 < currentSize && arr[index[j]] < arr[index[j + 1]]){
            ++j;
        }

        if (target >= arr[index[j]]){
            break;
        }

        index[k] = index[j];
        k = j;
    }
    index[k] = tarIndex;
}

#endif //SORTINGALGORITHMS_HEAPINDEX_H
