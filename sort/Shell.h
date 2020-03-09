//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_SHELL_H
#define SORTINGALGORITHMS_SHELL_H

#include "../util/ArrayHelper.h"
using namespace ArrayHelper;

template <class T>
class Shell{
public:
    void test();
    static void ShellSort(T* arr, int n);

};

template <class T>
void Shell<T>::test() {

    int sum = 9;
    int *arr = ArrayHelper::GenerateUnorderArray(sum, 0, sum);
    ArrayHelper::PrintArray(arr, sum);

    ShellSort(arr, sum);
    ArrayHelper::PrintArray(arr, sum);
}

template <class T>
void Shell<T>::ShellSort(T *arr, int n) {
    for (int gap = n/2; gap >= 1; gap = gap/2) {
        //insertion sort in each groups of elements [...i-gap-gap, i-gap, i]
        for (int i = gap; i < n; ++i) {
            int target = arr[i];
            int j = i - gap;
            while (j >= 0 && target < arr[j]) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = target;
        }
    }
}

#endif //SORTINGALGORITHMS_SHELL_H
