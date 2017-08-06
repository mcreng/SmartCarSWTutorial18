# C++ Programming - Basic - Assignment

## Author: Peter Tse (mcreng)

This assignment should be attempted by **all** members, regardless of being a software/non-software members in internal competition period.

### Introduction

Bytes and bits are common to see in embedded system, since they are controlled by digital signals and they can only be represented by high (1) and low (0). In this assignment, you will be handling binary and hexadecimal numbers which are different formats the embedded system can accept. 

Copy the following header file and put it in `byte.h`. Your job is to finish the five function implementations.

### Provided Header

```C++
/* byte.h */
/* Do not alter */
#include <cstdint>
typedef uint8_t Byte; // defining a new type 'Byte' to be equivalent to uint8_t

Byte set_bit(Byte byte, uint8_t n);
Byte reset_bit(Byte byte, uint8_t n);
bool get_bit(Byte byte, uint8_t n);
void print_bin(int bytes);
void print_hex(int bytes);
```

### Explanation

First, we define the digit number of the binary numbers.

```
0b11100111
  ^^^^^^^^
  87654321
```

Here provides the detailed explanations of functionalities of the five functions.

* `Byte set_bit(Byte byte, uint8_t n)`

  This returns a `Byte` with the $n$-th position of `Byte byte` changed to `1`.

  Expected output of `set_bit(0b00001110, 1)` is `15`.

* `Byte reset_bit(Byte byte, uint8_t n)`

  This returns a `Byte` with the $n$-th position of `Byte byte` changed to `0`.

  Expected output of `reset_bit(0b00001111, 1)` is `14`.

- `bool get_bit(Byte byte, uint8_t n)`

  This returns a `bool` equals to the $n$-th position of `Byte byte`.

  Expected output of `get_bit(0b00001110, 1)` is `0` or `false`.

- `void print_bin(int bytes)`

  This prints the integer in binary in the format `0b<binary>`. No trailing zeros.

  Expected output of `print_bin(15)` is `0b1111`.

- `void print_hex(int bytes)`

  This prints the integer in hexadecimal in the format `0x<hex>`. No trailing zeros.

  Expected output of `print_hex(15)` is `0xF`.

### Submission

Another C++ program which includes `byte.h` is used to check whether your functions have been implemented correctly. Please, therefore, make sure you do not change the filename and function names when you submit your files. Submission deadline is ????/??/??.