entire ayalysis:
Algorithms Name    Average Time Complexity   Sorting in itself   Space Complexity   Stability
Selection                 Sort O(n2)               √                    O(1)           √
Insertion                 Sort O(n2)               √                    O(1)           √
Bubble                    Sort O(n2)               √                    O(1)           √
Shell                     Sort O(nlgn)             √                    O(1)           √
Merge Sort                O(nlgn)                  ×                    O(n)           √
Quick                     Sort O(nlgn)             √                    O(lgn)         ×
Heap Sort                 O(nlgn)                  √                    O(1)           ×

time cause analysis:
100000 random integer elements from 0 to 100000
SelectSort : 12.632 S
InsertSort : 7.479 S
BubbleSort : 56.399 S
ShellSort : 0.031 S
MergeSort : 0.02 S
QuickSort1(Unbalanced) : 0.023 S
QuickSort2 : 0.018 S
QuickSort3Ways : 0.029 S
HeapSortSlow1 : 0.044 S
HeapSortSlow2 : 0.044 S
HeapSort : 0.043 S

200 random integer elements in 100000 size sorted array
SelectSort : 12.703 S
InsertSort : 0.008 S
BubbleSort : 13.251 S
ShellSort : 0.009 S
MergeSort : 0.002 S
QuickSort1(Unbalanced) : 0.013 S
QuickSort2 : 0.006 S
QuickSort3Ways : 0.022 S
HeapSortSlow1 : 0.047 S
HeapSortSlow2 : 0.032 S
HeapSort : 0.029 S

A large of equal elements in random elements from 0 to 10 in 100000 size array
SelectSort : 12.501 S
InsertSort : 6.637 S
BubbleSort : 53.194 S
ShellSort : 0.012 S
MergeSort : 0.013 S
QuickSort1(Unbalanced) : 1.348 S
QuickSort2 : 0.011 S
QuickSort3Ways : 0.005 S
HeapSortSlow1 : 0.031 S
HeapSortSlow2 : 0.031 S
HeapSort : 0.028 S

Summary:
Accoring to the analysis above, the most common used sorting algorithms is quick sort(3 ways).
