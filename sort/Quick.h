//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_QUICK_H
#define SORTINGALGORITHMS_QUICK_H


#include "../util/ArrayHelper.h"
using namespace ArrayHelper;

template <class T>
class Quick{
public:
    void testQuickSort();
    static void QuickSortI(T* arr, int n);
    static void QuickSortII(T* arr, int n);
    static void QuickSort3Way(T* arr, int n);

private:
    static int PartitionI(T * arr, int left, int right);
    static void QuickSortI(T *arr, int left, int right);

    static void QuickSortII(T *arr, int left, int right);
    static int PartitionII(T *arr, int left, int right);

    static void QuickSort3Way(T *arr, int left, int right);
};

template <class T>
void Quick<T>::testQuickSort() {
    int n = 10;
    int *arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    ArrayHelper::PrintArray(arr, n);
    QuickSortI(arr, n);
    ArrayHelper::PrintArray(arr, n);
}

//quick sort two
template <class T>
void Quick<T>::QuickSort3Way(T* arr, int n) {
    srand(time(NULL));
    QuickSort3Way(arr, 0, n-1);
}

template <class T>
void Quick<T>::QuickSort3Way(T *arr, int left, int right) {
    if (right - left <= 15){
        Insert<T>::InsertSort(arr, left, right);
        return;
    }

    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T target = arr[left];

    int lt = left;
    int gt = right + 1;
    int i = left + 1;
    while (i < gt){
        if (arr[i] < target){
            swap(arr[i], arr[lt + 1]);
            ++lt;
            ++i;
        } else if (arr[i] > target){
            swap(arr[i], arr[gt - 1]);
            --gt;
        } else {
            ++i;
        }
    }
    swap(arr[left], arr[lt]);

    //sort the part of the array whose elements less than the target
    QuickSort3Way(arr, left, lt  - 1);
    //sort the part of the array whose elements bigger than the target
    QuickSort3Way(arr, gt, right);
}


//quick sort two ways
template <class T>
void Quick<T>::QuickSortII(T* arr, int n) {
    srand(time(NULL));
    QuickSortII(arr, 0, n-1);
}

template <class T>
void Quick<T>::QuickSortII(T *arr, int left, int right) {
    if (right - left <= 15){
        Insert<T>::InsertSort(arr, left, right);
        return;
    }

    int middle = PartitionII(arr, left, right);
    QuickSortII(arr, left, middle - 1);
    QuickSortII(arr, middle + 1, right);
}

template <class T>
int Quick<T>::PartitionII(T *arr, int left, int right) {
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T target = arr[left];

    int i = left + 1, j = right;
    while (true){
        //begin from left, find the element bigger than target
        while (i <= right && arr[i] < target)
            ++i;

        //begin from right, find the element less than target
        while (j >= left && arr[j] > target)
            --j;

        //when i is larger than j, end this round of sorting
        if (i > j){
            break;
        }

        swap(arr[i], arr[j]);
        ++i;
        --j;
    }
    swap(arr[left], arr[j]);
    return j;
}


//quick sort one
template <class T>
void Quick<T>::QuickSortI(T* arr, int n) {
    srand(time(NULL));
    QuickSortI(arr, 0, n-1);
}

template <class T>
void Quick<T>::QuickSortI(T *arr, int left, int right) {
/*    if (left >= right){
        return;
    }*/

    //optimise, when the elements need to be sorted less than 15(or others value)
    //use Insert Sort will be better, cause less time
    if (right - left <= 15){
        Insert<T>::InsertSort(arr, left, right);
        return;
    }

    int middle = PartitionI(arr, left, right);
    //sort the first part of the array
    QuickSortI(arr, left, middle - 1);
    //sort the second part of the array
    QuickSortI(arr, middle + 1, right);
}

template <class T>
int Quick<T>::PartitionI(T *arr, int left, int right) {
    //optimise, if the array is almost a sorted array, the time complexity will reach O(n2),
    //so swap the target elements with a random index's value in the array.
    swap(arr[left], arr[rand() % (right - left + 1) + left]);
    T target = arr[left];

    int j = left;
    for (int i = left + 1; i <= right; ++i) {
        if (arr[i] < target){
            swap(arr[j+1], arr[i]);
            ++j;
        }
    }
    swap(arr[left], arr[j]);
    return j;
}

#endif //SORTINGALGORITHMS_QUICK_H
