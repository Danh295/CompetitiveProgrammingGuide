# Sorting

Fundamental to many algorithms; sorted data is easier to process

## Sorting Theory

Here's a basic example of a sorting problem:
> Given an array that contains 'n' elements, sort the elements in increasing order

*Input:* 1, 3, 8, 2, 9, 2, 5, 6 
*Output:* 1, 2, 2, 3, 5, 6, 8, 9

### O(n<sup>2</sup>) Algorithms

Simple algorithms for sorting an array commonly function with this time complexity

**Bubble Sort**
makes use of a nested for loop
- iterates through all the elements multiple times, checking 2 adjacent elements at a time
    - adjacent elements that aren't in order are swapped
    - process is repeated until all elements are sorted
- not an ideal sorting algorithm, especially for larger test cases

**Inversions**
