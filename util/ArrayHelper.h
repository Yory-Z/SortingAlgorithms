//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_ARRAYHEPLER_H
#define SORTINGALGORITHMS_ARRAYHEPLER_H


#include<iostream>
#include<ctime>
#include <cassert>

using namespace std;

namespace ArrayHelper{

    void PrintArray(int *arr, int n){
        for (int i = 0; i < n; ++i){
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }

    int* GenerateUnorderArray(int sum, int begin, int end){
        int* arr = new int[sum];
        srand(time(NULL));
        for (int i = 0; i < sum; ++i) {
            arr[i] = rand() % (end - begin + 1) + begin;
        }
        return arr;
    }

    int* GenerateNearlyOrderArray(int n, int swapTimes){
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        srand(time(NULL));
        for (int j = 0; j < swapTimes; ++j) {
            int posX = rand()%n;
            int posY = rand()%n;
            swap(arr[posX], arr[posY]);
        }
        return arr;
    }

    template <typename T>
    bool IsSorted(T *arr, int n){
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }

    template <typename T>
    void TestSort(const string &sortName, void (*sort)(T[], int), T *arr, int n){
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();

        assert(IsSorted(arr, n));
        cout<<sortName<<" : "<<double(endTime-startTime)/CLOCKS_PER_SEC<<" S"<<endl;
    }

    int* CopyArray(const int *arr, int n){
        int *a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = arr[i];
        }
        return a;
    }

}

#endif //SORTINGALGORITHMS_ARRAYHEPLER_H
