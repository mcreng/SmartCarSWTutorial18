# C++ Programming - Basic
## Author: Peter Tse (mcreng)

This section is intended for **non**-software members during the internal competition period.

### C++ Code Structure
Welcome to C++. C++ is somewhat similar to C, and its syntax partly adapts from C. Here in this note, some C-style syntax would be introduced. To begin, we shall look at a script of C++ codes.
```C++
#include <iostream>

int main(){
  // this is a comment
  /*
     This
     is
     a
     multiline
     comment
  */
  std::cout << "Hello World" << std::endl;
  return 0;
}
```
This is a basic structure of C++ codes. Here is the dissection:
* `#include <iostream>` is to include the library `iostream`, which is provided by C++ compiler itself.
* `int main(){}` is the program entry point. It should always ends with `return 0` because this specifies to the compiler that the program runs without errors.
* The above code would have no functionalities because we haven't programmed it to do anything.
* The included library `iostream` is used to print the text `Hello World` in line `std::cout << "..." << std::endl;`. Replacing the text inside `"..."` can make it print anything else.

### Variable Type
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
  char d = 'd'; // declared a character with name d and character d, note the single quotation
  float e = 0.0; // declared a float with name e and value 0.0, note the decimal point
  double f = 0.0; // declared a double with name f and value 0.0
  string g = "hello"; // declared a string with name g and string hello, note the double quotation
  return 0;
}
```
It is **highly recommend** that whenever you declare a variable, you should provide it an initial value (*initialization*).

When you would like to re-assign the variable, you can just call the variable name without the type. Otherwise, it is considered as re-creating the variable (which wastes some time).
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

#### Arithmetic Operators

Here is the list of arithmetic operators and the sample code.

| Arithmetic operator | Meaning        |
| ------------------- | -------------- |
| `+`                 | Addition       |
| `-`                 | Subtraction    |
| `*`                 | Multiplication |
| `/`                 | Division       |
| `%`                 | Modulus        |
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
  /*
     Remember if you wish to do division, always write
     int a = 2 / 5.0;
     instead of
     int a = 2 / 5;
     Otherwise, you would have repeated our team leader's mistake!!
  */
  c = a % b; // 10. a % b means finding the remainder of a div b
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

#### Relational Operators

Here is the list of relational operators, note that they all return the boolean type.

| Relational operator | Meaning                  |
| ------------------- | ------------------------ |
| `==`                | Equal to                 |
| `!=`                | Not equal to             |
| `>`                 | Bigger than              |
| `<`                 | Smaller than             |
| `>=`                | Bigger than or equal to  |
| `<=`                | Smaller than or equal to |

```C++
int main(){
  bool a;
  a = (1 == 2); // false
  a = (1 != 2); // true
  a = (1 > 2); // false
  a = (1 < 2); // true
  a = (1 >= 2); // false
  a = (1 <= 2); // true
  return 0;
}
```

#### Logical Operators

Here is list of logical operators, note that they all also return the boolean type. 

| Logical operator | Meaning |
| ---------------- | ------- |
| `&&`             | and     |
| `||`             | or      |
| `!`              | not     |

```C++
int main(){
  bool _true = true;
  bool _false = false;
  bool result;
  // and operator
  result = _true && _true; // true
  result = _true && _false; // false
  result = _false && _true; // false
  result = _false && _false; // false
  // or operator
  result = _true || _true; // true
  result = _true || _false; // true
  result = _false || _true; // true
  result = _false || _false; // false
  // not operator
  result = !_true; // false
  result = !_false; // true
}
```

#### Bitwise Operators

Bitwise operators are used to deal with bit by bit arithmetic, really useful when interacting with different electronic modules through low level library.

| Bitwise operator | Meaning     |
| ---------------- | ----------- |
| `&`              | Bitwise and |
| `|`              | Bitwise or  |
| `~`              | Bitwise not |
| `^`              | Bitwise xor |

```C++
int main(){
  int a = 0b1100; // this is a way to represent binary numbers in C++
  int b = 0b0110;
  int c;
  // bitwise and
  c = a & b; 
  // a = 1100
  // b = 0110
  // c = 0100 (bit by bit and)
  
  // bitwise or
  c = a | b;
  // a = 1100
  // b = 0110
  // c = 1110 (bit by bit or)
  
  // bitwise not
  c = ~a;
  // a = 1100
  // c = 0011 (bit by bit not)
  
  // bitwise xor
  c = a ^ b;
  // a = 1100
  // b = 0110
  // c = 1010 (bit by bit xor, only one 1 and one 0 returns 1, otherwise 0)
  
  return 0;  
}
```

### Scopes

Have you noticed the curly brackets `{ }` in our `main()` function? This is to define a *scope*, which you think of as a closure of declared variables and constants. In fact, you can define a variable outside `main()` and you would be still able to access it. It is called a *global variable*.

```C++
int outside = 10;
int main(){
  int inside = outside; // valid
  return 0;
}
```

You can even declare more scopes inside `main()` to separate different parts of your program.

```C++
int outside_main = 10;
int main(){
  int inside_main = outside_main; // valid
  {
    int inside_main_scope = inside_main; // valid
    inside_main_scope = outside_main; // valid
  }
  inside_main = inside_main_scope; // invalid, closure of scope!
}
```

In fact, variable names can repeat in different scope.

```C++
#include <iostream>
int main(){
  int n = 10;
  {
    int n = 5;
    std::cout << n << std::endl; // prints 5
  }
  std::cout << n << std::endl; // prints 10
  return 0;
}
```

But it will refer to outside scope if the variable is not declared inside the scope.

```C++
#include <iostream>
int main(){
  int n = 10;
  {
    n = 5;
    std::cout << n << std::endl; // prints 5
  }
  std::cout << n << std::endl; // prints 5
  return 0;
}
```

### Controls

In C++, there are several control blocks that you can use to simplify your code. Note the use of `{ }` (scopes).

#### if-then-else

As the name specified, this can check whether certain conditions are met.

```C++
#include <iostream>
int main(){
  int n = 5;
  if (n > 7){
    std::cout << "1" << std::endl;
  } else if (n > 6){
    std::cout << "2" << std::endl;
  } else {
    std::cout << "3" << std::endl;
  } // expected output: 3
  return 0;
}
```

If the code inside each scope contains only one sentence, you can omit the scope as it is not useful in this scenario.

```C++
#include <iostream>
int main(){
  int n = 5;
  if (n > 7) std::cout << "1" << std::endl;
  else if (n > 6) std::cout << "2" << std::endl;
  else std::cout << "3" << std::endl;
  //expected output: 3
  return 0;
}
```

There is a shorthand for `if` if you are using it to assign different values to a variable.

```C++
int main(){
  bool _certain_req = true;
  int n = _certain_req ? 2 : 5; // (condition ? true : false), n is now 2
  return 0;
}
```

#### switch-case

Switch-case is a convenient way to write out a bunch of if-then-else if necessary. Note the lack of scope in each `case`.

```C++
int main(){
  int a = 2;
  switch(a){
    case 1:
      std::cout << "a is 1" << std::endl;
      break; // since switch-case is adapted from assembly, without 'break' the code would just continue to run through other cases, so it is necessary if you do not wish it to execute the codes in other cases
    case 2:
      std::cout << "a is 2" << std::endl;
      break;
    case 3:
      std::cout << "a is 3" << std::endl;
      break;
  } // expected output: "a is 2"
  return 0;
}
```

If you do not include `break`:

```C++
int main(){
  int a = 2;
  switch(a){
    case 1:
      std::cout << "a is 1" << std::endl;
    case 2:
      std::cout << "a is 2" << std::endl;
    case 3:
      std::cout << "a is 3" << std::endl;
  } 
  // expected output: "a is 2"
                      "a is 3"
  return 0;
}
```

You should add the curly brackets if you wish to have separate scopes in each case.

```C++
int main(){
  int a = 2;
  switch(a){
    case 1:{
      std::cout << "a is 1" << std::endl;
      break;
    }
    case 2:{
      std::cout << "a is 2" << std::endl;
      break;
    }
    case 3:{
      std::cout << "a is 3" << std::endl;
      break;
    }
  } 
  return 0;
}
```

#### while



#### do-while



#### for



### Static Variables

### Functions

### Header

### Extern Variables



