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
SelectSort : 11.352 S<br/>
InsertSort : 6.249 S<br/>
BubbleSort : 48.584 S<br/>
ShellSort : 0.031 S<br/>
MergeSort : 0.02 S<br/>
QuickSort1(Unbalanced) : 0.021 S<br/>
QuickSort2 : 0.02 S<br/>
QuickSort3Ways : 0.029 S<br/>
HeapSortSlow1 : 0.031 S<br/>
HeapSortSlow2 : 0.039 S<br/>
HeapSort : 0.02 S<br/>
<br/>
<strong>200 random integer elements in 100000 size sorted array</strong><br/>
SelectSort : 10.378 S<br/>
InsertSort : 0.008 S<br/>
BubbleSort : 11.21 S<br/>
ShellSort : 0 S<br/>
MergeSort : 0.002 S<br/>
QuickSort1(Unbalanced) : 0.008 S<br/>
QuickSort2 : 0.003 S<br/>
QuickSort3Ways : 0.02 S<br/>
HeapSortSlow1 : 0.043 S<br/>
HeapSortSlow2 : 0.031 S<br/>
HeapSort : 0.008 S<br/>
<br/>
<strong>A large of equal elements in random elements from 0 to 10 in 100000 size array</strong><br/>
SelectSort : 10.288 S<br/>
InsertSort : 5.671 S<br/>
BubbleSort : 46.224 S<br/>
ShellSort : 0.018 S<br/>
MergeSort : 0.008 S<br/>
QuickSort1(Unbalanced) : 1.155 S<br/>
QuickSort2 : 0 S<br/>
QuickSort3Ways : 0 S<br/>
HeapSortSlow1 : 0.031 S<br/>
HeapSortSlow2 : 0.04 S<br/>
HeapSort : 0.014 S<br/>
<br/>
<h3>Summary:</h3><br/>
Accoring to the analysis above, the most common used sorting algorithms is quick sort(3 ways).<br/>

<strong>
  See more analyses:<br/>
  http://note.youdao.com/noteshare?id=afa74cc3942c8e00e6d31304cac2e069&sub=E7A44982BC064D0AAF3FD632A5DE309A
</strong>
