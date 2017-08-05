# C++ Programming - Basic
## Author: Peter Tse

### This section is intended for **non**-software members during the internal competition period.

#### C++ Code Structure
Welcome to C++. C++ is somewhat similar to C, and its syntax partly adapts from C. Here in this note, some C-style syntax would be introduced. To begin, we shall look at a script of C++ codes.
```C++
#include <iostream>

int main(){
  // this is a comment
  return 0;
}
```
This is a basic structure of C++ codes. Here is the dissection:
* `#include <iostream>` is to include the library `iostream`, which is provided by C++ compiler itself.
* `int main(){}` is the program entry point. It should always ends with `return 0` because this specifies to the compiler that the program runs without errors.
* The above code would have no functionalities because we haven't programmed it to do anything.
* The included library `iostream` is not used in the code.

#### Variable Type
As seen from the example above, in C++ we have variable types such as `int`. Here is a table of variable types that you might find useful.

| Type     | Descriptions                             |
| -------- | ---------------------------------------- |
| `int`    | integer, defaulted to be 32-bit signed integer |
| `bool`   | boolean, can be either `true` or `false` |
| `char`   | character, can store a single charater such as `'a'` |
| `float`  | float, single-precision floating point value |
| `double` | double, double-precision floating point value |
| `void`   | void, an absence of type                 |

The following types are also available if `cstdint` is included.

| Type       | Descriptions            |
| ---------- | ----------------------- |
| `uint8_t`  | unsigned 8-bit integer  |
| `uint16_t` | unsigned 16-bit integer |
| `uint32_t` | unsigned 32-bit integer |
| `int8_t`   | signed 8-bit integer    |
| `int16_t`  | signed 16-bit integer   |
| `int32_t`  | signed 32-bit integer   |

The type `string` is also available if `string` is included.

In C++, we can declare a variable in the following way. Note that the symbol `=` means 'assignment' in the following context.
```C++
#include <cstdint>
#include <string>

int main(){
  int a; // declared an integer with name d
  uint8_t b = 0; // declared an unsigned 8-bit integer with name b and value 0
  bool c = true; // declared a boolean with name c and value true
  char d = 'd'; // declared a character with name d and character d
  float e = 0.0; // declared a float with name e and value 0.0, note the decimal point
  double f = 0.0; // declared a double with name f and value 0.0
  string g = "hello"; // declared a string with name g and string hello
  return 0;
}
```
It is **highly recommend** that whenever you declare a variable, you should provide it an initial value (*initialization*).

When you would like to re-assign the variable, you can just call the variable name without the type. Otherwise, it is considered as re-creating the variable (which waste some time).
```C++
int main(){
  int a = 0; // a is 0
  a = 1; // now a is 1
  int a = 2; // a is re-created, and is now 2
  return 0;
}
```

You can also assign a variable with another variable.
```C++
int main(){
  int a = 0;
  int b = a; // assigned the value of a to b
  return 0;
}
```

When an assignment of a variable consists of other variables, there might be variable casting, especially if the types of the variables are different.

```C++
int main(){
  bool b = true;
  int n = b; // compiler casts a boolean to an integer, n would be 1 because true -> 1; false -> 0

  char c = 'c';
  n = c; // compiler casts a character to an integer, by using ASCII conversion, n is now 99

  float f = 0.55;
  n = f; // compiler casts a float to an integer, by truncating the floating point value, n is now 0, same goes with double

  uint8_t p = 6;
  uint16_t q = p; // compiler casts a 8-bit to a 16-bit, since 16-bit can hold larger values, q is also 6

  q = 678;
  p = q; // compiler casts a 16-bit to a 8-bit, since 8-bit cannot store a number this large, it overflows and goes back to 166 (678 in binary with only last 8 bits)

  int16_t j = -5;
  uint16_t k = j; // compiler casts a signed to unsigned, since it cannot store a negative number, it underflows and goes to 65531 (-5 in binary's two's compliment and converts to unsigned)
  
  return 0;
}
```
The type conversion above is an *implicit* casting, i.e. the compiler itself figures out the converted type. Usually, instead, we would prefer a safer approach, that we specify the converted type in our codes.

```C++
int main(){
  float f = 2.5;
  int n = (float)f; // C type conversion, n is now 2
  n = float(f); // C++ type conversion, n is now 2
  
  return 0;
}
```

It is **recommended** to use C++ type conversion, as you will see the reason in an upcoming section.

### Constants

Apart from variables (things that we can change), we can also specify things that cannot be changed (i.e. constants). There are two ways to define a constant. 

1. Using `#define`, **not recommended**

   ```C++
   #define CONSTANT_1 10

   int main(){
     int a = CONSTANT_1; // a is now 10
     CONSTANT_1 = 20; // illegal
     return 0;
   }
   ```

2. Using `const`, **recommended**

   ```C++
   int main(){
     const int a = 10;
     a = 20; // illegal
     return 0;
   }
   ```

Sometimes using `const` to specify certain items may prevent changing unchangeable values, making it safer.

### Operators

For different variables and constants, there are several operators available to be used. These include:

* Arithmetic operators
* Relational operators
* Logical operators
* Bitwise operators
* Assignment operators

#### Arithmetic operators

Here is the list of arithmetic operators and the sample code.

| Arithmetic operator | Meaning        |
| ------------------- | -------------- |
| `+`                 | Addition       |
| `-`                 | Subtraction    |
| `*`                 | Multiplication |
| `/`                 | Division       |
| `++`                | Increment      |
| `--`                | Decrement      |

 ```C++
int main(){
  int a = 10, b = 20; // note the use of comma here
  int c = a + b; // 30
  c = a - b; // -10
  c = a * b; // 200
  c = a / b; // 0, note that (int)/(int) -> (int)
  float d = 2.0;
  c = d / a; // 0.2, note that if one of the operands contain float, it returns float
  a++; // a = 11
  ++a; // a = 12
  a--; // a = 11
  --a; // a = 10
  // Here demostrate the difference between prefix and postfix increment/decrement
  c = a++; // c = 10, a = 10 -> 11; c keeps the value of a, then a increment
  c = ++a; // a = 11 -> 12, c = 12; a increment, then c keeps the value of a
  // the same goes with decrement
  return 0;
}
 ```

