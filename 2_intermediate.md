# C++ Programming - Intermediate

## Author: Dipsy Wong

 #### Preprocessor directives

Preprocessor directives are some codes for the compiler to read. During the compile time, the compiler will compile the code according to the preprocessor directives by replacing the code to be compiled.

###### A.`#define`

```C++
#include <iostream>
#define MY_AGE 18
int main(){
  std::cout<<MY_AGE;
}
```

The output will be `18`. But `MY_AGE` is not a variable, it is fixed by `#define`(mentioned in constant section in basic section). It is done by replacing `MY_AGE` with 18 during the compile time, so the code actually look like this in the view of compiler:

```C++
#include <iostream>
int main(){
  std::cout<<18;
}
```

And this is the reason why value of `MY_AGE` cannot be changed.

###### B. `#include`, `#ifndef` and  `#endif` 

`#include` works by copying the code. For example, 

`main.cpp`

```C++
#include "hello.h"
#include "foo.h"
...
```

This will copy all of the content of `hello.h` to `main.cpp`.

However, if `hello.h` also have to include `foo.h` , there will be two copies of `foo.h` in the compilation. At this moment, we need to use `#ifndef` `#endif` to make sure the content of `foo.h` only include once.

```C++
#ifndef FOO_H
#define FOO_H
int bar(){
  return 1234;
}
#endif
```

Then, when `foo.h` is included the first time, compiler will find `FOO_H` haven't be defined, then it will compile code between `#ifndef` and `#endif` , and define `FOO_H` , so when `foo.h` is included the second time, compiler will find `FOO_H` is already defined and will not compile code between `#ifndef` and `#endif`.

As a result, these are very useful for `.h` files.  

###### C. `#pragma`

You may see `#pragma once` in some codes for embedded system too. It is a non-standard way to make sure the file is only included once, and it supports most of the processors. You may choose either the `#ifndef` - `#define` - `#endif` sequence or `#pragma once`, but we recommend the former one.

####  Array

An array is a variable will can store list of things. If a variable acts like a box, array is the cabinet. Array can be declared like this:

```C++
//a boolean array which can store 100 true false values;
bool bool_array[100];

//an integer array which can store 10 integers
//with first element is 0, second is 1, etc.
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
```

Be careful, array which have variable length can only be declared inside scope.

```C++
#include <iostream>
int x = 10;
bool y[x]; //invalid array declaration
int main(){
  bool z[x]; //valid array declaration
}
```

To get and set value of array, we use `[]` operator. Always remember, the very first index is always `0` !

```C++
std::cout<<a[0]; //print the first element of array a. 
a[12] = true; //set the value of the element having index 12 in array a to true
```

There is also multi-dimension array. It works like array of array, which still can be used easily.

```C++
//a integer array which have 3 row (actually each row is another integer //array), each row have 5 element
int matrix[3][5]={
  {0,1,2,3,4},
  {5,6,7,8,9},
  {10,11,12,13,14}
};

std::cout<<matrix[1][3];//get matrix's index 1 row's index 3 element, which is 8
matrix[1][3] = 100; //set matrix's index 1 row's index 3 element's value to 100 
```

If you wish to initialize each elements of an array with certain values, you may use a for loop. Or, if you just want to zero all the elements, you may do the following.

```C++
#include <cstring> // need this for memset()
int main(){
  int a[n]; // n is any arbitrary number
  memset(a, 0, sizeof(a)); // or memset(a, 0, sizeof(int) * n); or memset(a, 0, a[0] * n);
  int matrix[n][m]; // n & m are any arbitrary numbers
  memset(matrix, 0, sizeof(matrix[0][0]) * n * m); // or memset(matrix, 0, sizeof(int) * n * m);
}
```

Note: `sizeof` would return the allocated space (in byte) for certain variable type.

#### String

String is actually array of characters. They can be used like an array.

```C++
#include <iostream> 
#include <cstring>	//for data type string, standard string

int main(){
	char a[5] = {'h','e','l','l','o'}; //char array style declaration
	char b[6] = "world";	//string style declaration, which always end by a null character ('\o') implicitly
	string str = "lol";		//standard string style declaration, actually is a dynamic length character array
  
	std::cout<<a<<" "<<b<<std::endl;	//output hello world
	std::cout<<str<<std::endl;		//output lol
	
  //output hello in vertical
    for (int i=0; i<5; i++){
		std::cout<<a[i]<<std::endl;	
	}
  
  //output world in vertical
	for (int i=0; i<5; i++){
		std::cout<<b[i]<<std::endl;	
	}
  
  //output lol in vertical
	for (int i=0; i<5; i++){
		std::cout<<str[i]<<std::endl;	
	}
}
```

String methods (Not for standard string so sad)

| method              | description                            |
| ------------------- | -------------------------------------- |
| `strcpy(str1,str2)` | copy the content of `str2` to `str1`   |
| `strcat(str1,str2)` | append the content of `str2` to `str1` |

There are more methods left for you to discover (#

#### Reference

Reference is the address of variable, which is meant by `&` operator. First, we need to know memory. Memory is the way our C++ program store variable value, which is store in an address inside the memory pool. When we are getting or setting value of the variable, actually we are accessing its address. 

```C++
//declare integer x, let's assume its address is 0x123456
int x = 10;	

//define integer y have same address as x, 0x123456, which mean x and y always have same value. 
int& y = x;	

//display the value of y, which mean display the value stored in 0x123456 which is 10
std::cout<<y<<std::endl; 	

//set value of x to 20, which mean set the value stored in 0x123456 to 20
x = 20;	

//display the value of y, which mean display the value stored in 0x123456 which is 20
std::cout<<y<<std::endl;  

//set value of y to 50, which mean set the value stored in 0x123456 to 50
y = 50; 

//display the value of x, which mean display the value stored in 0x123456 which is 50
std::cout<<x<<std::endl;	
```

So you can see x and y always have same value.

Note: The memory address of variable is fixed when defined, so the operation `int& y = x ` can only be done in declaration.

#### Pointer

##### Pointer Basics

Pointer is a variable type which can store a memory address. Pointer will be useful when we need to deal with variables across function scope. Let us call the variable that "the pointer is pointing to" "pointee". To get the address of a variable, we use `&`. To get the value of pointee, we add a `*` before the pointer. For example:

```C++
//declare a integer x, assume its address is 0x123456
int x = 12;

//&x is getting the address of x, which this line will print out 0x123456
std::cout<<&x<<std::endl; //output: 0x123456

//declare a integer pointer pInt pointing to the address of x, which is 0x123456
int* pInt = &x;

//output the value of pInt, which is 0x123456
std::cout<<pInt<<std::endl; //output: 0x123456

//output the value of pointee of pInt, which means printing the value in address 0x123456, which is 12
std::cout<<*pInt<<std::endl; //output: 12

//change the value of x, which mean changing the value in address 0x123456
x = 24;

//output the value of pointee of pInt, which means printing the value in address 0x123456, which is 24
std::cout<<*pInt<<std::endl;	//output: 24

//change the value of pointee of pInt to 48, which means changing the value in address 0x123456 to 48
*pInt = 48;

//print out the value of x, which means printing the value on 0x123456, which is 48
std::cout<<x<<std::endl;	//output: 48
```

Note: To declare a pointer with no initial pointee, we can use `NULL` (C style) or `nullptr` (c++0x style). Both of them meaning a pointer pointing to nothing. `nullptr` recommended.

**Be careful, never change the value of pointee of pointer which is pointing to nothing.** This will change the value in a random location inside the memory pool, result in hard fault (the program suddenly stop while running).

```C++
float* foo = NULL;
unsigned char* bar = nullptr;

//**never do this, as foo and var are both pointing to nothing**
*foo = 123;	//result: your program GG
*bar = 'd';	//result: your program GG
```

Task: make a swap function

```C++
int a = 3, b = 10;     //a and b can be any value
//do a swap function
std::cout<<a<<" "<<b<<std::endl; //10 3
```

##### Array as a Pointer

Array is actually a pointer pointing to its first element, and a string is actually a character pointer pointing to the first character. For example:

```C++
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
std::cout<<int_array<<std::endl; //print the address of first element
std::cout<<*int_array<<std::endl; //print the value of first element, which is 0

char buff[12]="hello world";
std::cout<<*buff<<std::endl;	//print out h
```

##### Memory offset

If we plus or minus some value with the pointer, we can access its neighbor, and this is how array works.

```C++
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
std::cout<<int_array<<" "<<*int_array<<std::endl;		//0x100000 0
std::cout<<int_array+1<<" "<<*(int_array+1)<<std::endl;	//0x100004 1
std::cout<<int_array+2<<" "<<*(int_array+2)<<std::endl;	//0x100008 2
```

So you can see, `any_array[n]` is totally equivalent to `*(any_array+n)`. Notice that each address is storing 1 byte, so if you plus `n` to the address, the memory offset is `n` times the size of variable, like in the example, the size of integer is 4 byte, so the offset is `n*4`. To get the size of a variable, we can use `sizeof(myVar)`, and so if we do

##### Array Memory Allocation

This is to allocate some places in the memory pool to build the array using pointer. Remember, delete the array after finishing using it, or you will be wasting memory. If you keep allocating without deleting it, it will result in memory leaks, and the program may crash at anytime.

```C++
int* x = nullptr; 	//deinfe a pointer
x = new int[12];	//allocate a size of 12 integers to x
//some usage for x
delete [] x;		//release allocated memory of x
```

#### Data Structure

This chapter we will talk about `enum` and `struct`.

##### Enum

Enum is actually using enumerator to represent different numerical values. This will make the code look nicer. Maybe an example will be clearer.

```C++
//enum <enum name> = {enumerator,enumerator,enumerator,...};

enum robotics_subteam = {kRoboCon, kRov, kSmartCar};
std::cout<<kRoboCon<<std::endl;		//output: 0
std::cout<<kRov<<std::endl;			//output: 1
std::cout<<kSmartCar<<std::endl;	//output: 2
```

In the above case, we are actually using 0 to represent RoboCon, 1 to represent ROV, 2 to represent smart car. It will look better if we use enumerator rather than using 0,1,2 to represent our sub-teams, but at the end both are using integers to do operation.

We can also change the data type stored in enum (but must still be integer) and change the value stored in the enumerator in enum:

```C++
enum robotics_subteam:uint8_t = {
  kRoboCon = 2,
  kRov,		//implicitly kRov is 3 (previous +1)
  kSmartCar = 5
}
```

If there is multiple enum having same enumerator, you need to add `<enum_name>::` before the enumerator. For example:

```C++
std::cout<<robotics_subteam::kSmartCar;
```

See details in namespace.

##### Struct

Struct is a data structure which can store multiple data type in one, including function. In practice, we use capital letters to define struct and class (class will talk later). If you need to access elements inside the struct, you need to use dot.

```C++
//define a struct Foo, and Foo will become a new data type for you
struct Human{			
  int age = 0;			//the items are seperated with semicolon
  void PrintAge(){
    std::cout<<age<<std::endl;	//variable inside struct can be access without dot (.) when it is accessed iside its own struct
  }
};	//don't forget this semicolon

int main(){
  Human dipsy;		//now you have a new Human, and its name is dipsy
  dipsy.PrintAge();	//tell dipsy to print his age, output 0
  dipsy.age = 18;	//set dipsy's age to 18	
  dipsy.PrintAge();	//tell dipsy to print his age, output 18
}
```

If the struct does not contain default value for the variable, you can declare it using `{}`. The above example have default value for age, so it can't declare it using `{}`. The below one is a valid one. 

```C++
struct Human{
  int age;
  float GPA;
  char* name;
  bool inRelationship;
  void Greet(){
    std::cout<<"Hello, my name is "<<name<<"!"<<std::endl;
  }
};

//declare Human peter, assigning value according to its sequence
//age=18, GPA=4.0, name=peter, inRelationship=false
Human peter = {18,4.0,"peter",false}; 
int main(){
  peter.Greet();	//Hello, my name is peter!
}
```

For struct pointer, we use `->` instead of `.` when we are dealing elements inside the struct pointee. For example,

```C++
struct Human{
  int age;
  float GPA;
  char* name;
  bool inRelationship;
  void Greet(){
    std::cout<<"Hello, my name is "<<name<<"!"<<std::endl;
  }
};

//declare a human pointer pointing to nothing
Human* pHuman = nullptr;

void PlayedOneYearOfSmartCar(){
  pHuman->age++;
  pHuman->GPA = 4.3;
  pHuman->inRelationship = true;
}

int main(){
  Human peter = {18,4.0,"peter",false}; 
  pHuman = &peter;	//let pHuman pointing to peter
  std::cout<<peter.inRelationship<<std::endl;//this prints false
  PlayedOneYearOfSmartCar();
  std::cout<<peter.inRelationship<<std::endl;//now it is true
}
```

Now you can see the power of playing one year smart car and the `->` operator~

#### Namespace

Namespace is a space to place variables. Inside a namespace, the name of variables must be unique, while across namespace, 

