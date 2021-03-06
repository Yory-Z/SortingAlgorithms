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
SelectSort : 12.543 S<br/>
InsertSort : 7.344 S<br/>
BubbleSort : 57.102 S<br/>
ShellSort : 0.03 S<br/>
MergeSort : 0.02 S<br/>
QuickSort1(Unbalanced) : 0.037 S<br/>
QuickSort2 : 0.018 S<br/>
QuickSort3Ways : 0.03 S<br/>
HeapSort : 0.024 S<br/>
<br/>
<strong>200 random integer elements in 100000 size sorted array</strong><br/>
SelectSort : 12.358 S<br/>
InsertSort : 0.008 S<br/>
BubbleSort : 13.24 S<br/>
ShellSort : 0.01 S<br/>
MergeSort : 0.003 S<br/>
QuickSort1(Unbalanced) : 0.013 S<br/>
QuickSort2 : 0.007 S<br/>
QuickSort3Ways : 0.023 S<br/>
HeapSort : 0.016 S<br/>
<br/>
<strong>A large of equal elements in random elements from 0 to 10 in 100000 size array</strong><br/>
SelectSort : 12.419 S<br/>
InsertSort : 6.731 S<br/>
BubbleSort : 54.934 S<br/>
ShellSort : 0.013 S<br/>
MergeSort : 0.013 S<br/>
QuickSort1(Unbalanced) : 1.378 S<br/>
QuickSort2 : 0.011 S<br/>
QuickSort3Ways : 0.005 S<br/>
HeapSort : 0.018 S<br/>
<br/>
<h3>Summary:</h3><br/>
According to the analysis above, the most common used sorting algorithms is quick sort(3 ways).<br/>
When the elements need to be sorted is almost ordered,  the insertion sort is the fastest algorithm.<br/>
When using merge sort or quick sort and the number of elements need to be sorted is small, then it would be faster when using insertion sort to sort the rest elements.<br/>
When sorting, it will must change two elements' index. Now, we should save the element which need to change the index, when finding the correct index for element, we can use overriding instead of swapping. After we found the correct index, we just place the element need to chang to the found index. This way will cut down much time cause.<br/>
<br/>
<strong>
  See more analyses:<br/>
  http://note.youdao.com/noteshare?id=c9bd03f95575061c12dc8686a72dc4f0&sub=4904D9DB001F4DBA9015E29E0876B9FB
</strong>
