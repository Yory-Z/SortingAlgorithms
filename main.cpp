#include <iostream>

#include "util/ArrayHelper.h"

#include "sort/Select.h"
#include "sort/Insert.h"
#include "sort/Shell.h"
#include "sort/Quick.h"
#include "sort/Bubble.h"
#include "sort/Merge.h"
#include "sort/PriorityQueue.h"
#include "sort/Heap.h"

#include "advanced/PriorityQueueIndex.h"
#include "advanced/PriorityQueueReverseIndex.h"

void test();
void testSort();

int main(){
    test();
    return 0;
}

void test() {

    PriorityQueueIndex<int> test;
    test.test();
}

void testSort(){

    int n = 100000;
    int from = 0, to = n;
    cout<<n<<" random integer elements from "<<from<<" to "<<n<<endl;
    int *arr1 = ArrayHelper::GenerateUnorderArray(n, from, to);
    int *arr2 = ArrayHelper::CopyArray(arr1, n);
    int *arr3 = ArrayHelper::CopyArray(arr1, n);
    int *arr4 = ArrayHelper::CopyArray(arr1, n);
    int *arr5 = ArrayHelper::CopyArray(arr1, n);
    int *arr6 = ArrayHelper::CopyArray(arr1, n);
    int *arr7 = ArrayHelper::CopyArray(arr1, n);
    int *arr8 = ArrayHelper::CopyArray(arr1, n);
    int *arr9 = ArrayHelper::CopyArray(arr1, n);

    ArrayHelper::TestSort("SelectSort", Select<int>::SelectionSort, arr1, n);
    ArrayHelper::TestSort("InsertSort", Insert<int>::InsertSort, arr2, n);
    ArrayHelper::TestSort("BubbleSort", Bubble<int>::BubbleSort, arr3, n);
    ArrayHelper::TestSort("ShellSort", Shell<int>::ShellSort, arr4, n);
    ArrayHelper::TestSort("MergeSort", Merge<int>::MergeSort, arr5, n);
    ArrayHelper::TestSort("QuickSort1(Unbalanced)", Quick<int>::QuickSortI, arr6, n);
    ArrayHelper::TestSort("QuickSort2", Quick<int>::QuickSortII, arr7, n);
    ArrayHelper::TestSort("QuickSort3Ways", Quick<int>::QuickSort3Way, arr8, n);
    ArrayHelper::TestSort("HeapSort", Heap<int>::HeapSort, arr9, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    cout<<endl;


    int swapTimes = 100;
    cout<<swapTimes * 2<<" random integer elements in "<<n<<" size sorted array"<<endl;
    arr1 = ArrayHelper::GenerateNearlyOrderArray(n, swapTimes);
    arr2 = ArrayHelper::CopyArray(arr1, n);
    arr3 = ArrayHelper::CopyArray(arr1, n);
    arr4 = ArrayHelper::CopyArray(arr1, n);
    arr5 = ArrayHelper::CopyArray(arr1, n);
    arr6 = ArrayHelper::CopyArray(arr1, n);
    arr7 = ArrayHelper::CopyArray(arr1, n);
    arr8 = ArrayHelper::CopyArray(arr1, n);
    arr9 = ArrayHelper::CopyArray(arr1, n);

    ArrayHelper::TestSort("SelectSort", Select<int>::SelectionSort, arr1, n);
    ArrayHelper::TestSort("InsertSort", Insert<int>::InsertSort, arr2, n);
    ArrayHelper::TestSort("BubbleSort", Bubble<int>::BubbleSort, arr3, n);
    ArrayHelper::TestSort("ShellSort", Shell<int>::ShellSort, arr4, n);
    ArrayHelper::TestSort("MergeSort", Merge<int>::MergeSort, arr5, n);
    ArrayHelper::TestSort("QuickSort1(Unbalanced)", Quick<int>::QuickSortI, arr6, n);
    ArrayHelper::TestSort("QuickSort2", Quick<int>::QuickSortII, arr7, n);
    ArrayHelper::TestSort("QuickSort3Ways", Quick<int>::QuickSort3Way, arr8, n);
    ArrayHelper::TestSort("HeapSort", Heap<int>::HeapSort, arr9, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    cout<<endl;


    from = 0, to = 10;
    cout<<"A large of equal elements in random elements from "<<from<<" to "<<to<<" in "<<n<<" size array"<<endl;
    arr1 = ArrayHelper::GenerateUnorderArray(n, from, to);
    arr2 = ArrayHelper::CopyArray(arr1, n);
    arr3 = ArrayHelper::CopyArray(arr1, n);
    arr4 = ArrayHelper::CopyArray(arr1, n);
    arr5 = ArrayHelper::CopyArray(arr1, n);
    arr6 = ArrayHelper::CopyArray(arr1, n);
    arr7 = ArrayHelper::CopyArray(arr1, n);
    arr8 = ArrayHelper::CopyArray(arr1, n);
    arr9 = ArrayHelper::CopyArray(arr1, n);


    ArrayHelper::TestSort("SelectSort", Select<int>::SelectionSort, arr1, n);
    ArrayHelper::TestSort("InsertSort", Insert<int>::InsertSort, arr2, n);
    ArrayHelper::TestSort("BubbleSort", Bubble<int>::BubbleSort, arr3, n);
    ArrayHelper::TestSort("ShellSort", Shell<int>::ShellSort, arr4, n);
    ArrayHelper::TestSort("MergeSort", Merge<int>::MergeSort, arr5, n);
    ArrayHelper::TestSort("QuickSort1(Unbalanced)", Quick<int>::QuickSortI, arr6, n);
    ArrayHelper::TestSort("QuickSort2", Quick<int>::QuickSortII, arr7, n);
    ArrayHelper::TestSort("QuickSort3Ways", Quick<int>::QuickSort3Way, arr8, n);
    ArrayHelper::TestSort("HeapSort", Heap<int>::HeapSort, arr9, n);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;
    cout<<endl;

}

