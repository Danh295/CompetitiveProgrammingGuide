# Sorting

Fundamental to many algorithms; sorted data is easier to process

## Sorting Theory

Here's a basic example of a sorting problem:
> Given an array that contains 'n' elements, sort the elements in increasing order

*Input:* 1, 3, 8, 2, 9, 2, 5, 6 
*Output:* 1, 2, 2, 3, 5, 6, 8, 9

### O(n<sup>2</sup>) Algorithms

Simple algorithms for sorting an array commonly function with this time complexity

#### Bubble Sort

*Refer to attached file for c++ code

An algorithm that makes use of a nested for loop
- iterates through all the elements multiple times, checking 2 adjacent elements at a time
    - adjacent elements that aren't in order are swapped
    - process is repeated until all elements are sorted
- not an ideal sorting algorithm, especially for larger test cases

#### Inversions

Concept useful for analyzing sorting algorithms
An *inversion* is a pair of array elements that are in the wrong order
- an array is sorted if there are no inversions

*For example, the following array has 3 inversions:*
- (6, 3)
- (6, 5)
- (9, 8)
```c++
int arr[8] = {1, 2, 2, 6, 3, 5, 9, 8};
```
### O(n log n) Algorithms

Sorting arrays with much better efficiencies
- unlimited to swapping consective elements

**Merge Sort:**
Divide and conquer algorithm, based on recursion
- continuously halves itself and calls the function on itself to sort the array

<p align="center">
    <img alt="merge sort diagram" width="500px" src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Merge-Sort-Tutorial.png" />
</p>

*Pseudocode:*
```c++
void mergeSort(l, h) { // l is the lower cap, the starting index of the array; h is the higher cap, the ending index of the array
    if (l < h>) {
        mid = (l+j) / 2
        mergeSort(l, mid)
        mergeSort(mid + 1, h)
        merge(l, mid, h) // merge will combine the 2 divided parts and sort them
    }
}
```

The merge function will take the two split arrays and merge them
- split arrays will already be sorted; only a single loop is needed to sort collectively and merge
    - compare the elements by index and add them to the output array

Refer to attached file for basic implementation of the algorithm

### Sorting Lower Bound
Sorting algorithms based on *comparing* array elements are limited to O(n log n)

*O(n log n) time is the fastest possible time in a comparision type sorting algorithm
- different algorithms will be faster under different circumstances 
    - merge sort is NOT ALWAYS the fastest

### Counting Sort
The lower bound of n log n doesn't apply for algorithms that don't compare elements
- algorithms can use other information to sort arrays

**Couting Sort:**
Sorts an array in O(n) time
- applicable only for *positive integers*

Makes use of a *bookkeeping* array
- indices of the array are the elements of the original array
- tracks the occurance of each element

*Here's an example:*
The orginal array might be: 1, 3, 6, 9, 9, 3, 5, 9
The bookkeeping array would be: 1, 0, 2, 0, 1, 1, 0, 0, 3
- *eg. the value at position 3 in the bookkeeping array is 2, since the number '3' appeares twice in the original array*

Constructing the bookkeeping array takes O(n) time, the resutling array can then be constructed and outputted with O(n) time again

Although this is a very efficient algorithm, it's only applicable when the array is small enough and its elements are all positive integers

## Sorting in C++

-
