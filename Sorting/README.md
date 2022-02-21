# Sorting

Fundamental to many algorithms; sorted data is easier to process

## Sorting Theory

Here's a basic example of a sorting problem:

"Given an array that contains ```n``` elements, sort the elements in increasing order"

Input: ```1, 3, 8, 2, 9, 2, 5, 6```

Output: ```1, 2, 2, 3, 5, 6, 8, 9```

### O(n<sup>2</sup>) Algorithms

Simple algorithms for sorting an array commonly function with this time complexity

#### Bubble Sort

*Refer to attached file for c++ code

An algorithm that makes use of a nested for loop
- iterates through all the elements multiple times, checking 2 adjacent elements at a time
    - adjacent elements that aren't in order are swapped
    - process is repeated until all elements are sorted
- not ideal, especially for larger test cases

#### Inversions

Concept useful for analyzing sorting algorithms
An *inversion* is a pair of array elements that are in the wrong order
- an array is sorted if there are no inversions

*For example, the following array has 3 inversions:*
```c++
int arr[8] = {1, 2, 2, 6, 3, 5, 9, 8};
```
- (6, 3)
- (6, 5)
- (9, 8)
  
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

O(n log n) time is the fastest possible time in a comparision type sorting algorithm
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
The C++ standard library contains many implementations and functions that can carry out sorting algorithms for you
- making your own algorithm isn't always ideal
- using stl functions has many benefits
    - saves time
    - 100% functional & efficient
    - likely better than the function you code

**```sort``` function:**
C++ standard library function that sorts arrays
- defaulted to increasing order
- *introsort* algorithm
- worst case: O(n log n)
    - efficiency & effectiveness can depend on situation

*The following sorts a vector in increasing order:*
```c++
vector<int> v = {4, 2, 5, 3, 8, 3};
sort(v.begin(), v.end());
```
- ```v.begin()``` and ```v.end()``` are iterator values for the scope of the function
    - referred to as pointer values
- sorted vector is ```{2, 3, 3, 4, 5, 5, 8}```

*The following sorts an integer array:*
```c++
sort(arr, arr + n);
```
- ```n``` is the size of the array, ```arr``` is the name of the array

*The following sorts a vector in reverse (decreasing) order:*
```c++
sort(v.rbegin(), v.rend());
// or
sort(v.begin(), v.end(), greater<int>());
```
- ```.rbegin()``` and ```.rend()``` returns reverse iterators pointing to the opposite end of the container, which will reverse the order
- using iterators for normal arrays may not be ideal
    - passing ```greater<>()``` works just the same
    - ```greater<>()``` is a functional object for performing comparisions

***IMPORTANT:*** To use the ```greater<>()``` function, must pass the header file ```<functional.h\>```

Strings can also be sorted with this function
- they will be sorted by ASCII value, in alphabetical order
    - *eg. "monkey" becomes "ekmnoy"*

### Comparision Operators
The sort function requires a comparision operator for the data type of the elements to be sorted

Most data types have operators built-in like ```int```; these data types are automatically sorted:
  
- **```int```** sorted by value
- **```string```** sorted by alphabet
- **```pair```** sorted by value of ```first```
    - if ```first``` of 2 elements are equal, ```second``` is used instead

*The following sorts a vector of pairs:*
```c++
vector<pair<int, int>> v;
v.push_back({1, 5});
v.push_back({2, 3});
v.push_back({1, 2});
sort(v.begin(), v.end());
```
- sorted vector is ```{{1, 2}, {1, 5}, {2, 3}}```

**```tuple```** sorted primarily by first element
- if first elements are equal, following elements will be compared
  - second elements compared first; if equal, move on to third; if equal, move on to fourth, etc

*The following sorts a vector of tuples*
```c++
vector<tuple<int, int, int>> v;
v.push_back({2, 1, 4});
v.push_back({1, 5, 3});
v.push_back({2, 1, 3});
sort(v.begin(), v.end());
```
- sorted vector is ```{{1, 5, 3}, {2, 1, 3}, {2, 1, 4}}```

### User-defined structures

Usual comprison operators aren't applicable

- define operator as a function ```operator<```
    - same type element as parameter
    - return ```true``` if element smaller than parameter, ```false``` otherwise

*The following struct ```P``` contains x & y coords of a point*
- *comparison operator primarily sorts x-value, secondarily by y-value*
```c++
struct P {
    int x, y;

    // comparison operator function
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
}
```

### Comparion functions
External comparison functions can be given to ```sort``` function as a callback function

*The following function ```comp``` sorts strings by primarily length and secondaryly by alphabetical order*
```c++
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size(); 
    return a < b;
}
```
*A vector of strings can now be sorted as follows*
```c++
sort(v.begin(), v.end(), comp);
```
