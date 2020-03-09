//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_BUBBLE_H
#define SORTINGALGORITHMS_BUBBLE_H


#include "../util/ArrayHelper.h"

template <class T>
class Bubble {
public:
    void test();
    static void BubbleSort(T* arr, int n);
};

template <class T>
void Bubble<T>::test() {
    int n = 10;
    int *arr = ArrayHelper::GenerateUnorderArray(n, 0, n);
    ArrayHelper::PrintArray(arr, n);
    BubbleSort(arr, n);
    ArrayHelper::PrintArray(arr, n);
}

template <class T>
void Bubble<T>::BubbleSort(T *arr, int n) {
    for (int i = 1; i < n; ++i) {
        //the maximum element will be placed to the last index of each round
        for (int j = 0; j < n - i; ++j) {
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


#endif //SORTINGALGORITHMS_BUBBLE_H
