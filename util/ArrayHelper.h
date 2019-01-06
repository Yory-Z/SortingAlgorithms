//
// Created by Yory on 2019/1/5.
//

#ifndef SORTINGALGORITHMS_ARRAYHEPLER_H
#define SORTINGALGORITHMS_ARRAYHEPLER_H


#include<iostream>
#include<ctime>
#include <cassert>
#include <cmath>

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

    template <class T>
    class HeapHelper {
    public:
        static void PrintHeap(const T* arr, const int size){
            // 我们的testPrint只能打印100个元素以内的堆的树状信息
            if( size >= 100 ){
                cout<<"This print function can only work for less than 100 int";
                return;
            }

            // 我们的testPrint只能处理整数信息
            if( typeid(T) != typeid(int) ){
                cout <<"This print function can only work for int item";
                return;
            }

            cout<<"The max heap size is: "<<size<<endl;
            cout<<"Data in the max heap: ";
            for( int i = 0 ; i < size ; i ++ ){
                // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
                assert( arr[i] >= 0 && arr[i] < 100 );
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<endl;

            int n = size;
            int max_level = 0;
            int number_per_level = 1;
            while( n > 0 ) {
                max_level += 1;
                n -= number_per_level;
                number_per_level *= 2;
            }

            int max_level_number = int(pow(2, max_level-1));
            int cur_tree_max_level_number = max_level_number;
            int index = 0;
            for( int level = 0 ; level < max_level ; level ++ ){
                string line1 = string(max_level_number*3-1, ' ');

                int cur_level_number = min(size -int(pow(2,level))+1,int(pow(2,level)));
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

    private:
        static void putNumberInLine( int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft){
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
        static void putBranchInLine( string &line, int index_cur_level, int cur_tree_width){
            int sub_tree_width = (cur_tree_width - 1) / 2;
            int sub_sub_tree_width = (sub_tree_width - 1) / 2;
            int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
            assert( offset_left + 1 < line.size() );
            int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
            assert( offset_right < line.size() );

            line[offset_left + 1] = '/';
            line[offset_right + 0] = '\\';
        }
    };
}

#endif //SORTINGALGORITHMS_ARRAYHEPLER_H
