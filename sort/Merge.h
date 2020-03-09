//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_MERGE_H
#define SORTINGALGORITHMS_MERGE_H


#include "../util/ArrayHelper.h"
using namespace ArrayHelper;

template <class T>
class Merge {
public:
    static void test();
    static void MergeSort(T* arr, int n);
    static void MergerSortBottomUp(T* arr, int n);

private:
    static void MergeSort(T* arr, int left, int right);
    static void MergeTwoSet(T* arr, int left, int mid, int right);
};

template <class T>
void Merge<T>::test() {
    int n = 10;
    int* arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    ArrayHelper::PrintArray(arr, n);
    MergeSort(arr, n);
    ArrayHelper::PrintArray(arr, n);
}

template <class T>
void Merge<T>::MergerSortBottomUp(T *arr, int n) {
    for (int size = 1; size <= n ; size += size) {
        for (int i = 0; i + size < n; i += size + size) {
            if (size <= 15){
                Insert<T>::InsertSort(arr, i, min(i + size + size - 1, n - 1));
                continue;
            }

            if (arr[i+size-1] > arr[i+size])
                MergeTwoSet(arr, i, i + size - 1, min(i + size + size - 1, n - 1));
        }
    }
}

template <class T>
void Merge<T>::MergeSort(T *arr, int n) {
    MergeSort(arr, 0, n-1);
}

template <class T>
void Merge<T>::MergeSort(T *arr, int left, int right) {
    if (left >= right)
        return;

    //optimise
/*    if (right - left <= 15){
        Insert<T>::InsertSort(arr, left, right);
        return;
    }*/

    //divide the array into two arrays
    //int mid = (left + right) / 2;// this will cause memory leak
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    //merge the two arrays
    if (arr[mid] > arr[mid + 1])    //optimise
        MergeTwoSet(arr, left, mid, right);
}

template <class T>
void Merge<T>::MergeTwoSet(T *arr, int left, int mid, int right) {
    //need temporary memory, copy the array
    T temp[right - left + 1];
    for (int i = left; i <= right; ++i) {
        temp[i - left] = arr[i];
    }

    int i = left, j = mid + 1;
    //find the smaller elements to put into the array
    for (int k = left; k <= right; ++k) {
        if (i > mid){
            arr[k] = temp[j - left];
            ++j;
        } else if(j > right){
            arr[k] = temp[i - left];
            ++i;
        }else if (temp[i - left] < temp[j - left]){
            arr[k] = temp[i - left];
            ++i;
        } else {
            arr[k] = temp[j - left];
            ++j;
        }
    }
}

#endif //SORTINGALGORITHMS_MERGE_H
