//
// Created by Yory on 2019/1/6.
//

/*
 * Priority Queue reverse index.
 * (This version just can insert in a time. it means you can not insert after extracting.
 * Because when inserting a elements, the index would override the existent elements's index)
 *
 * */

#ifndef SORTINGALGORITHMS_PRIORITYQUEUEREVERSEINDEX_H
#define SORTINGALGORITHMS_PRIORITYQUEUEREVERSEINDEX_H


#include <cassert>
#include <ctime>

#include "../util/HeapHelper.h"

template <typename T>
class PriorityQueueReverseIndex {
public:
    static void testPriorityQueueReverseIndex();
    PriorityQueueReverseIndex(int capacity = 100);
    ~PriorityQueueReverseIndex();

    void Insert(T item);
    T ExtractMax();
    bool IsEmpty();
    void Change(int i, T item);

private:
    int capacity;
    int currentSize;

    T* arr;
    int* index;
    int* reverse;

    void ShiftDown(int k);
    void ShiftUp(int k);
    void Print();
};

template <typename T>
void PriorityQueueReverseIndex<T>::testPriorityQueueReverseIndex() {
    int n = 10;
    PriorityQueueReverseIndex<T> queue = PriorityQueueReverseIndex<T>(n);
    srand(time(NULL));
    for (int i = n; i > 0; --i) {
        int temp = rand() % 10;
        cout<<temp<<' ';
        queue.Insert(temp);
    }
    cout<<endl;

    while (!queue.IsEmpty()){
        cout<<queue.ExtractMax()<<' ';
    }
}

template <typename T>
PriorityQueueReverseIndex<T>::PriorityQueueReverseIndex(int capacity): capacity(capacity), currentSize(0) {
    arr = new T[capacity];
    index = new int[capacity];
    reverse = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
        reverse[i] = -1;
    }
}

template <typename T>
PriorityQueueReverseIndex<T>::~PriorityQueueReverseIndex() {
    delete []arr;
    delete []index;
    delete []reverse;
}

template <typename T>
void PriorityQueueReverseIndex<T>::Insert(T item) {
    assert(currentSize < capacity);

    //this index may be existent
    index[currentSize] = currentSize;
    reverse[currentSize] = currentSize;
    arr[currentSize] = item;

    ShiftUp(currentSize);
    ++currentSize;
}

template <typename T>
T PriorityQueueReverseIndex<T>::ExtractMax() {
    assert(currentSize != 0);

    T max = arr[index[0]];
    --currentSize;
    arr[index[0]] = arr[index[currentSize]];

    //because this version just can insert in a time, so do not need to update the index and reverse
/*    index[0] = index[currentSize];
    reverse[currentSize] = 0;*/

    ShiftDown(0);
    return max;
}

template <typename T>
bool PriorityQueueReverseIndex<T>::IsEmpty() {
    return currentSize == 0;
}

template <typename T>
void PriorityQueueReverseIndex<T>::Change(int i, T item) {
    assert(i >= 0 && i < currentSize);

    arr[i] = item;
    //find the value of index i, this way course O(n)
    //the order of ShiftDown and ShiftUp have no effect
/*    for (int j = 0; j < currentSize; ++j) {
        if (index[j] == i){
            ShiftDown(j);
            ShiftUp(j);
        }
    }*/

    /*
     * Optimise
     * Use reverse index, we can find the value of index i in O(1) time complexity
     * index[i] = j;
     * reverse[j] = i;
     * index[reverse[j]] = j;
     * reverse[index[i]] = i;
     * */
    int k = reverse[i];
    ShiftUp(k);
    ShiftDown(k);
}

template <typename T>
void PriorityQueueReverseIndex<T>::ShiftUp(int k) {
    T target = arr[index[k]];
    int tarIndex = index[k];

    while (k > 0 && arr[index[(k - 1) / 2]] < target){
        index[k] = index[(k - 1) / 2];
        reverse[index[(k - 1) / 2]] = k;
        k = (k - 1) / 2;
    }

    index[k] = tarIndex;
    reverse[tarIndex] = k;
}

template <typename T>
void PriorityQueueReverseIndex<T>::ShiftDown(int k) {
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
        reverse[index[j]] = k;
        k = j;
    }

    index[k] = tarIndex;
    reverse[tarIndex] = k;
}

template <typename T>
void PriorityQueueReverseIndex<T>::Print() {
    cout<<"Array: "<<endl;
    HeapHelper<T>::PrintHeap(arr, currentSize);
    cout<<"Index: "<<endl;
    HeapHelper<T>::PrintHeap(index, currentSize);
}


#endif //SORTINGALGORITHMS_PRIORITYQUEUEREVERSEINDEX_H
