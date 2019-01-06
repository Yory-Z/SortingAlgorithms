cmake_minimum_required(VERSION 3.13)
project(SortingAlgorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(SortingAlgorithms main.cpp util/ArrayHelper.h sort/Bubble.h sort/Heap.h sort/Insert.h sort/PriorityQueue.h sort/Merge.h sort/Quick.h sort/Select.h sort/Shell.h)