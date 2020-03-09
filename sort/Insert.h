//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_INSERT_H
#define SORTINGALGORITHMS_INSERT_H


#include "../util/ArrayHelper.h"
using namespace ArrayHelper;

template <class T>
class Insert {
public:
    void test();
    static void InsertSort(T* arr, int n);
    static void InsertSortSlow(T* arr, int n);
    static void InsertSort(T* arr, int left, int right);
};

template <class T>
void Insert<T>::test() {
    int n = 10;
    int *arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    int *arr2 = ArrayHelper::CopyArray(arr, n);
    ArrayHelper::PrintArray(arr, n);
    ArrayHelper::PrintArray(arr2, n);
    cout<<n<<" random integer elements from 0 to "<<n<<endl;
    ArrayHelper::TestSort("InsertSort", InsertSort, arr, n);
    ArrayHelper::TestSort("InsertSortSlow", InsertSortSlow, arr2, n);
    ArrayHelper::PrintArray(arr, n);
    ArrayHelper::PrintArray(arr2, n);
}

template <class T>
void Insert<T>::InsertSort(T* arr, int n) {
    for (int i = 1; i < n; ++i) {
        T target = arr[i];
        int j;
        //optimise, just override the first index's(need to find the correct location) value
        for (j = i; j > 0 && target < arr[j-1]; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = target;
    }
}

template <class T>
void Insert<T>::InsertSortSlow(T* arr, int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && arr[j] < arr[j-1]; --j) {
            //this way will swap two index's value, will cause much time
            swap(arr[j], arr[j-1]);
        }
    }
}

template <class T>
void Insert<T>::InsertSort(T *arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        T target = arr[i];
        int j;
        for (j = i; j > left && target < arr[j - 1] ; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = target;
    }
}

#endif //SORTINGALGORITHMS_INSERT_H
