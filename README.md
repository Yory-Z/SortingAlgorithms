<table>
  <tr>
    <th>Algorithms Name</th>
    <th>Average Time Complexity</th>
    <th>Sorting in itself</th>
    <th>Space Complexity</th>
    <th>Stability</th>
  </tr>
  <tr>
    <td>Selection Sort</td>
    <td>O(n2)</td>
    <td>√</td>
    <td>O(1)</td>
    <td>√</td>
  </tr>
  <tr>
    <td>Insertion Sort</td>
    <td>O(n2)</td>
    <td>√</td>
    <td>O(1)</td>
    <td>√</td>
  </tr>
  <tr>
    <td>Bubble Sort</td>
    <td>O(n2)</td>
    <td>√</td>
    <td>O(1)</td>
    <td>√</td>
  </tr>
  <tr>
    <td>Shell Sort</td>
    <td>O(nlgn)</td>
    <td>√</td>
    <td>O(1)</td>
    <td>√</td>
  </tr>
  <tr>
    <td>Merge Sort</td>
    <td>O(nlgn)</td>
    <td>x</td>
    <td>O(n)</td>
    <td>√</td>
  </tr>
  <tr>
    <td>Quick Sort</td>
    <td>O(nlgn)</td>
    <td>√</td>
    <td>O(lgn)</td>
    <td>×</td>
  </tr>
  <tr>
    <td>Heap Sort</td>
    <td>O(nlgn)</td>
    <td>√</td>
    <td>O(1)</td>
    <td>×</td>
  </tr>
</table>

<h2>Time cause analysis:</h2><br/>
100000 random integer elements from 0 to 100000<br/>
SelectSort : 12.632 S<br/>
InsertSort : 7.479 S<br/>
BubbleSort : 56.399 S<br/>
ShellSort : 0.031 S<br/>
MergeSort : 0.02 S<br/>
QuickSort1(Unbalanced) : 0.023 S<br/>
QuickSort2 : 0.018 S<br/>
QuickSort3Ways : 0.029 S<br/>
HeapSortSlow1 : 0.044 S<br/>
HeapSortSlow2 : 0.044 S<br/>
HeapSort : 0.043 S<br/>

<strong>200 random integer elements in 100000 size sorted array</strong><br/>
SelectSort : 12.703 S<br/>
InsertSort : 0.008 S<br/>
BubbleSort : 13.251 S<br/>
ShellSort : 0.009 S<br/>
MergeSort : 0.002 S<br/>
QuickSort1(Unbalanced) : 0.013 S<br/>
QuickSort2 : 0.006 S<br/>
QuickSort3Ways : 0.022 S<br/>
HeapSortSlow1 : 0.047 S<br/>
HeapSortSlow2 : 0.032 S<br/>
HeapSort : 0.029 S<br/>

<strong>A large of equal elements in random elements from 0 to 10 in 100000 size array</strong><br/>
SelectSort : 12.501 S<br/>
InsertSort : 6.637 S<br/>
BubbleSort : 53.194 S<br/>
ShellSort : 0.012 S<br/>
MergeSort : 0.013 S<br/>
QuickSort1(Unbalanced) : 1.348 S<br/>
QuickSort2 : 0.011 S<br/>
QuickSort3Ways : 0.005 S<br/>
HeapSortSlow1 : 0.031 S<br/>
HeapSortSlow2 : 0.031 S<br/>
HeapSort : 0.028 S<br/>

<h2>Summary:</h2><br/>
Accoring to the analysis above, the most common used sorting algorithms is quick sort(3 ways).<br/>
