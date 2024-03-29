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

C++ often considered as the best choice for competitive programming
- nearly always available in contest systems
- efficient high-capacity language
- standard library contains numerous data structures and algorithms
Choice of programming language can still depend on preference, as python and java are still good options, but C++ will be the main language of this repository

# Input and Output

In most contests standard streams are used for input/ouput
- Works with the console

## ```cin``` and ```cout```

- standard I/O streams
- when printing on a new line for outputs, using ```"\n"``` is faster than ```endl```

Including the following lines at the beginning of code can make input/output more efficient for cin and cout
```c++
ios::sync_with_stdio(0);
```
- all standard streams are synchronized by default, which allows to mix C and C++ I/O
    - disabling the synchronization, C++ streams will become independent and have their own buffers, making it slightly faster and prevents mixing different I/O streams

```c++
cin.tie(nullptr);
cout.tie(nullptr);
```
- tied streams ensure sensible user interaction, where one stream is flushed automatically before each I/O on the other stream
    - this function unties the io streams, so they must be flushed manually everytime it's used
    - can be more efficient since you control when and where you flush

## ```scanf``` and ```printf```
Primary I/O stream in C 
- also applicable for C++ instead of using its standard streams
- a bit faster but harder to use

The following lines takes input and prints 2 integers
```c++
int a, b;
scanf("%d %d". &a, &b);
printf("%d %d\n", a, b);
```

In order to read a whole line from input, containing spaces, use the 'getline' function as following:
```c++
string s;
getline(cin, s);
```
- ```cin``` and ```scanf``` both stop taking inputs at a white space character

If there's an unkown amount of data, consider using a while loop:
```c++
while(cin >> x) {
    // code goes here
}
```
- the loop reads elements from the input one after another, until there are no more

# Working with Numbers

## Integers

Most common integer type: 'int'
- 32-bit (value range of -2<sup>31</sup> to 2<sup>31</sup>-1)

If type 'int' is not enough, there's 'long long'
- 64-bit type integer (value range of -2<sup>63</sup> to 2<sup>63</sup>-1)

```c++
long long x = 123456789123456789LL;
int y = 2
long long b = y*y; // this will produce an incorrect result
long long b = (long long)y*y; // this will produce a correct result
```
- suffix ```LL``` now defines the number type of long long
- ```long long``` type is not interexchangeable with int type, an error may otherwise occur

## Modular Arithmetic

Modulous of 2 numbers is the remainder value of their division
- the remainder of a negative is either 0 or negative in C++
    - calculate the remainder as usual and add m to the result if it's negative
    - only needed if subtractions are invovled; remainders wouldn't be negative otherwise

```c++
x = x%m;
if (x < 0) x += m;
``` 

**Property of the remainder**: in addition, subtraction, and multiplication, the remainder can be taken before the operation:
> (a + b) mod m = (a mod m + b mod m) mod m <br>
> (a - b) mod m = (a mod m - b mod m) mod m <br>
> (a * b) mod m = (a mod m * b mod m) mod m <br>
- useful to avoid long long type; the number can never get too large

## Floating Point Numbers

```double``` type floating point
- 64-bit 

```long double``` type floating point
- 80-bit
- extension in the g++ compiler

To output a predtermined number of decimals, ```printf``` can be used as following:
```c++
printf("%.9\n", x);
```
- outputs the value with 9 decimal places

Keep in mind that this method may return rounding errors as following:
```c++
double x = 0.3*3 + 0.1;
printf("%20f\n", x); // 0.99999999999999988898
```
- due to rounding error, the value of ```x``` is slightly less than 1, which is the correct value
- due to this, floating point numbers shouldn't be compared with the == operator

When **comparing floating point numbers**, assume that 2 numbers are equal if their difference is less than ε
- 'ε' is generally assumed to be eqaul to 10<sup>-9</sup>
```c++
if(abs(a-b) < 1e-9) { // 1e-9 means "one times ten to the negative ninth power"
    // a and b are equal
}
```

# Shortening Code

Important in competitive programming to save time
- try to use shorter names for datatypes, variables, etc

## Type names

Using the function ```typedef``` datatypes can be given shorter names

For example:
```c++
// long long can be simplified as ll
typedef long long ll;

ll a = 123456789;
ll b = 987654321;
cout << a*b << "\n";

// can also be used with complex types
typedef vector<int> vi;
typedef pair<int, int> pi;
```

## Macros

Using the keyword ```#define```, strings can be changed before the compilation

For example:
```c++
// first and second can be reduced to F and S; push_back and make_pair can be reduced to PB and MP
#define F first
#define S second
#define PB push_back
#define MP make_pair

v.PB(MP(x1, y1));
v.PB(MP(x2, y2));
int d = v[i].F + v[i].S;
```

Macros can even have parameters to shorten loops and other structures:
```c++
#define REP(i, a, b) for (int i = a; i <= b; i++)

REP(i, 1, n) {
    search(i);
}
```

# Mathematics

Absolutely essential for competitive programming
- This sections contains some useful formulas to remember

## Sum formulas

### **Sum of an arithmetic progression**
Incrementing sequence of numbers with common difference

***a + ... + b = [n(a + b)] / 2***
- n is the number of terms
- a is the first number
- b is the last number

*Here's an example:*
*1 + 2 + 3 + ... + n = [n(n + 1)]/2*
*3 + 7 + 11 + 15 = [4(3 + 15)] / 2 = 36*

### **Sum of a geometric progression**
Incrementing seqeunce of numbers with common ratio

***ak<sup>0</sup> + ak<sup>1</sup> + ak<sup>2</sup> + ... + b = (bk - 1) / (k - 1)***
- a is the first number
- b is the last number
- k is the ratio 

*Here's an example:*
*3 + 6 + 12 + 24 = (24 * 2 - 3) / (2 - 1) = 45*

<!-- Harmonic Sum -->

## Set Theory

**Set:** a collection of elements
- *Intersection* A ∩ B: elements that are in both sets
- *Union* A ∪ B: all unique elements in both sets
- *Complement* of set A: elements that are not in the set but are in the universal set
    - eg. if A = {1, 2, 5, 7} and the universal set is {1, 2, ..., 10}, the complement of A is {3, 4, 6, 8, 9, 10}
- *Difference* A \ B: elements are in A but not B
    - eg. if A = {2, 3, 7, 8} and B = {3, 5, 8}, then A \ B = {2. 7}

If all elements of A also belongs to S, then A is a **subset** of S (A ⊂ S)

## Logic
Values of a logical expression are **true** and **false**
- 1 is true
- 0 is false

**Negation:** True if false; false if true<br>
**Conjuction:** True if both are true<br>
**Disjunction:** True if either or both are true<br>
**Implication:** True when the other is also true<br>
**Equivalence:** True if both are the same<br> 

***Predicate:*** An expression true or false depending on its parameters
- a predicate can be defined to be true when x is a prime number
    - denoted as 'P(x)'

***Quantifier:*** Logical expression for elements of a set
- eg. expression is true if *for all* elements *there is* an even integer

## Functions
Basic functions:
- rounding
- max (of a set)
- min (of a set)

### **Factorial**
***n! = 1 * 2 * 3 * ... * n***

### **Fibonacci** 
***f(n) = f(n - 1) + f(n - 2)***

## Logarithms
Logarithm of a number x: ***log<sub>k</sub>(x)***
- k is the base
- log<sub>k</sub>(x) = a, k<sup>a</sup> = x

Often used in analysis of algorithm efficiency
- dividing/reducing the number of steps at each step

**Useful property:**
log<sub>k</sub>(x) = number of times to divide x by k before reaching 1
- eg. log<sub>2</sub>(32) = 5, 32/2/2/2/2/2 = 1 (divided by 2 five times)

<!-- Contests and resources -->

