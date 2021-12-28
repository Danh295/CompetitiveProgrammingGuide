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

#### Merge Sort

Divide and conquer algorithm, based on recursion
- continuously halves itself and calls the function on itself to sort the array

<img class="center" alt="merge sort diagram" width="500px" src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/Merge-Sort-Tutorial.png" /> <br>

*Pseudocode:*
```c++
mergeSort(l, h) { // l is the lower cap, the starting index of the array; h is the higher cap, the ending index of the array
    if (l < h) {
        int mid = (l+j)/2
        mergeSort(l, mid)
        mergeSort(mid+1, h)
        merge(l, mid, h) // merge will combine the 2 divided parts and sort them
    }
}
```
