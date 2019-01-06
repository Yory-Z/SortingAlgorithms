<h3>Complexity</h3>
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

<h3>Time cause analysis:</h3><br/>
<strong>100000 random integer elements from 0 to 100000</strong><br/>
SelectSort : 11.979 S<br/>
InsertSort : 7.133 S<br/>
BubbleSort : 55.564 S<br/>
ShellSort : 0.033 S<br/>
MergeSort : 0.019 S<br/>
QuickSort1(Unbalanced) : 0.025 S<br/>
QuickSort2 : 0.017 S<br/>
QuickSort3Ways : 0.031 S<br/>
HeapSortSlow1 : 0.049 S<br/>
HeapSortSlow2 : 0.05 S<br/>
HeapSort : 0.028 S<br/>
<br/>
<strong>200 random integer elements in 100000 size sorted array</strong><br/>
SelectSort : 12.445 S<br/>
InsertSort : 0.006 S<br/>
BubbleSort : 13.071 S<br/>
ShellSort : 0.009 S<br/>
MergeSort : 0.002 S<br/>
QuickSort1(Unbalanced) : 0.013 S<br/>
QuickSort2 : 0.007 S<br/>
QuickSort3Ways : 0.02 S<br/>
HeapSortSlow1 : 0.049 S<br/>
HeapSortSlow2 : 0.032 S<br/>
HeapSort : 0.015 S<br/>
<br/>
<strong>A large of equal elements in random elements from 0 to 10 in 100000 size array</strong><br/>
SelectSort : 12.198 S<br/>
InsertSort : 6.789 S<br/>
BubbleSort : 54.71 S<br/>
ShellSort : 0.012 S<br/>
MergeSort : 0.013 S<br/>
QuickSort1(Unbalanced) : 1.372 S<br/>
QuickSort2 : 0.013 S<br/>
QuickSort3Ways : 0.004 S<br/>
HeapSortSlow1 : 0.032 S<br/>
HeapSortSlow2 : 0.029 S<br/>
HeapSort : 0.015 S
<br/>
<h3>Summary:</h3><br/>
Accoring to the analysis above, the most common used sorting algorithms is quick sort(3 ways).<br/>

<strong>
  See more analyses:<br/>
  http://note.youdao.com/noteshare?id=afa74cc3942c8e00e6d31304cac2e069&sub=E7A44982BC064D0AAF3FD632A5DE309A
</strong>
