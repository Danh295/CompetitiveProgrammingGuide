# Introduction

Competitive programming combines the **design of algorithms** and the **implementation of algorithms**

## The design of algorithms

Analyzing problems & creative problem solving; and algorithms should be correct and efficient
- mathematical & creative thinking
- combination of theoretical knowledge

## The implementation of algorithms

Applying theoretical algorithms through code; not only does the theoritical portion be correct, but the implementation must also be efficient and correct

# Programming Languages

Most popular languages used in contests:
- C++
- Java
- Python

C++ often considered as the best choice for competitive3 programming
- nearly always available in contest systems
- efficient high-capacity language
- standard library contains numerous data structures and algorithms
Choice of programming language can still depend on preference, as python and java are still good options, but C++ will be the main language of this repository

# Input and Output

In most contests standard streams are used for input/ouput
C++: use 'cin' for input and 'cout' for output
- standard i/o streams
- when printing on a new line for outputs, using "\n" is faster than "endl"

Including the following lines at the beginning of code can make input/output more efficient for cin and cout
```
ios::sync_with_stdio(0);
cin.tie(0);
```

C: 'scanf' and 'printf' can also be used
- also applicable for C++ instead of using its standard streams
- a bit faster but harder to use

The followign lines takes input and prints 2 integers
```
int a, b;
scanf("%d %d". &a, &b);
printf("%d %d\n", a, b);
```

In order to read a whole line from input, containing spaces, use the 'getline' function as following:
```
string s;
getline(cin, s);
```
- 'cin' and 'scanf' both stop taking inputs at a white space character

If there's an unkown amount of data, consider using a while loop:
```
while(cin >> x) {
    // code goes here
}
```
- the loop reads elements from the input one after another, until there are no more

# Working with Numbers

## Integers

Most common integer type
- 32-bit (value range of -2<sup>31</sup> to 2<sup>31</sup>-1)

If type 'int' is not enough, use '**long long**'
- 64-bit type integer (value range of -2<sup>63</sup> to 2<sup>63</sup>-1)

```
long long x = 123456789123456789LL;
int y = 2
long long b = y*y; // this will produce an incorrect result
long long b = (long long)y*y; // this will produce a correct result
```
- suffix 'LL' defines the number type of long long
- long long type is not interexchangeable with int type, an error may otherwise occur

## Modular Arithmetic

Modulous of 2 numbers is the remainder value of their division
*eg. x mod m is the remainder of x divied by m*
- the remainder of a negative is either 0 or negative in C++
    - calculate the remainder as usual and add m to the result if it's negative
   
    ```
    x = x%m;
    if (x < 0) x += m;
    ``` 

**Property of the remainder**: in addition, subtraction, and multiplication, the remainder can be taken before the operation:
>(a + b) mod m = (a mod m + b mod m) mod m <br>
>(a - b) mod m = (a mod m - b mod m) mod m <br>
>(a * b) mod m = (a mod m * b mod m) mod m <br>
- useful to avoid long long type; the number can never get too large









