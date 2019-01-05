//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_MAXHEAPSLOW_H
#define SORTINGALGORITHMS_MAXHEAPSLOW_H


#include<cassert>
#include "../util/ArrayHelper.h"
#include <cmath>

template <typename T>
class MaxHeapSlow {
public:
    static void HeapSort1(T *arr, int n);
    static void HeapSort2(T *arr, int n);

    explicit MaxHeapSlow(int capacity = 100);
    explicit MaxHeapSlow(T *arr, int n);
    ~MaxHeapSlow();

    void Insert(T item);
    T ExtractMax();
    bool IsEmpty();
    void PrintHeap();

private:
    int capacity;
    T* arr;
    int currentSize;
    void ShiftUp(int k);
    void ShiftDown(int k);

    int size();
    void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft);
    void putBranchInLine( string &line, int index_cur_level, int cur_tree_width);
};

template <typename T>
void MaxHeapSlow<T>::HeapSort1(T *arr, int n) {
    MaxHeapSlow<T> maxHeap = MaxHeapSlow<T>(n);
    for (int i = 0; i < n; ++i) {
        maxHeap.Insert(arr[i]);
    }

    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
void MaxHeapSlow<T>::HeapSort2(T *arr, int n) {
    MaxHeapSlow<T> maxHeap = MaxHeapSlow<T>(arr, n);
    for (int j = n - 1; j >= 0; --j) {
        arr[j] = maxHeap.ExtractMax();
    }
}

template <typename T>
MaxHeapSlow<T>::MaxHeapSlow(int capacity): capacity(capacity) {
    currentSize = 0;
    arr = new T[capacity + 1];
}

template <typename T>
MaxHeapSlow<T>::MaxHeapSlow(T *arr, int n): capacity(n) {
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
MaxHeapSlow<T>::~MaxHeapSlow() {
    delete[] arr;
}

template <typename T>
void MaxHeapSlow<T>::Insert(T item) {
    assert(currentSize + 1 <= capacity);

    arr[++currentSize] = item;
    ShiftUp(currentSize);
}

template <typename T>
void MaxHeapSlow<T>::ShiftUp(int k) {
    while (k > 1 && arr[k/2] < arr[k]){
        swap(arr[k], arr[k/2]);
        k /= 2;
    }
}

template <typename T>
T MaxHeapSlow<T>::ExtractMax() {
    assert(currentSize != 0);
    T res = arr[1];
    arr[1] = arr[currentSize--];
    ShiftDown(1);
    return res;
}

template <typename T>
bool MaxHeapSlow<T>::IsEmpty() {
    return currentSize == 0;
}

template <typename T>
void MaxHeapSlow<T>::ShiftDown(int k) {
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

template <typename T>
void MaxHeapSlow<T>::PrintHeap(){
    // 我们的testPrint只能打印100个元素以内的堆的树状信息
    if( size() >= 100 ){
        cout<<"This print function can only work for less than 100 int";
        return;
    }

    // 我们的testPrint只能处理整数信息
    if( typeid(T) != typeid(int) ){
        cout <<"This print function can only work for int item";
        return;
    }

    cout<<"The max heap size is: "<<size()<<endl;
    cout<<"Data in the max heap: ";
    for( int i = 1 ; i <= size() ; i ++ ){
        // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
        assert( arr[i] >= 0 && arr[i] < 100 );
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    int n = size();
    int max_level = 0;
    int number_per_level = 1;
    while( n > 0 ) {
        max_level += 1;
        n -= number_per_level;
        number_per_level *= 2;
    }

    int max_level_number = int(pow(2, max_level-1));
    int cur_tree_max_level_number = max_level_number;
    int index = 1;
    for( int level = 0 ; level < max_level ; level ++ ){
        string line1 = string(max_level_number*3-1, ' ');

        int cur_level_number = min(size() -int(pow(2,level))+1,int(pow(2,level)));
        bool isLeft = true;
        for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
            putNumberInLine( arr[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
            isLeft = !isLeft;
        }
        cout<<line1<<endl;

        if( level == max_level - 1 )
            break;

        string line2 = string(max_level_number*3-1, ' ');
        for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
            putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
        cout<<line2<<endl;

        cur_tree_max_level_number /= 2;
    }
}

template <typename T>
int MaxHeapSlow<T>::size() {
    return currentSize;
}

template <typename T>
void MaxHeapSlow<T>::putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
    assert(offset + 1 < line.size());
    if( num >= 10 ) {
        line[offset + 0] = '0' + num / 10;
        line[offset + 1] = '0' + num % 10;
    }
    else{
        if( isLeft)
            line[offset + 0] = '0' + num;
        else
            line[offset + 1] = '0' + num;
    }
}

template <typename T>
void MaxHeapSlow<T>::putBranchInLine( string &line, int index_cur_level, int cur_tree_width){

    int sub_tree_width = (cur_tree_width - 1) / 2;
    int sub_sub_tree_width = (sub_tree_width - 1) / 2;
    int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
    assert( offset_left + 1 < line.size() );
    int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
    assert( offset_right < line.size() );

    line[offset_left + 1] = '/';
    line[offset_right + 0] = '\\';
}


#endif //SORTINGALGORITHMS_MAXHEAPSLOW_H
