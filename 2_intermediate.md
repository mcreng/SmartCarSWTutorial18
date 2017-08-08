# C++ Programming - Intermediate

## Author: Dipsy Wong

### This section is intended for non-software members during the internal competition period

 #### Preprocessor directives

Preprocessor directives are some code for the compiler to read. During the compile time, the compiler will compile the code according to the preprocessor directives by replacing the code to be compiled.

###### A.`#define`

```C++
#include <iostream>
#define MY_AGE 18
int main(){
  cout<<MY_AGE;
}
```

The output will be `18`. But `MY_AGE` is not a variable, it is fixed by `#define`(mentioned in constant section in basic section). It is done by replacing `MY_AGE` with 18 during the compile time, so the code actually look like this in the view of compiler:

```C++
#include <iostream>
int main(){
  cout<<18;
}
```

And this is the reason why value of `MY_AGE` cannot be changed

###### B. `#ifndef` `#endif` 

`#include` works by copying the code. For example, 

`main.cpp`

```C++
#include "hello.h"
#include "foo.h"
...
```

This will copy all of the content of `hello.h` to `main.cpp`.

However, if `hello.h` also have to include `foo.h` , there will be two definition of `foo.h` contents. At this moment, we need to use `#ifndef` `#endif` to make sure the content of `foo.h` only include once.

```C++
#ifndef FOO_H
#define FOO_H
int bar(){
  return 1234;
}
#endif

```

Then, when `foo.h` is included the first time, compiler will find `FOO_H` haven't defined, then it will compile code between `#ifndef` and `#endif` , and define `FOO_H` , so when `foo.h` is included the second time, compiler will find `FOO_H` is already defined and will not compile code between `#ifndef` and `#endif`.

As a result, these are very useful for `.h` files.  



####  Array

An array is a variable will can store list of things. If a variable acts like a box, array is the cabinet. Array can be declared like this:

```C++
//an boolean array which can store 100 true false value;
bool bool_array[100];

//an integer array which can store 10 integers
//with first element is 0, second is 1, etc.
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
```

Be careful, array which have variable length can only be declared inside scope.

```C++
#include <iostream>
using namespace std;
int x = 10;
bool y[x]; //invalid array declaration
int main(){
  bool z[x]; //valid array declaration
}
```

To get and set value of array, we use `[]` operator. Always remember, the very first index is always `0` !

```C++
cout<<a[0]; //print the first element of array a. 
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

cout<<matrix[1][3];//get matrix's index 1 row's index 3 element, which is 8
matrix[1][3] = 100; //set matrix's index 1 row's index 3 element's value to 100 
```

Note: if you want each element in the array have a initial, you need to set it one by one. A for loop will do.



#### String

String is actually array of characters. They can be used like an array.

```C++
#include <iostream> 
#include <cstring>	//for data type string, standard string
using namespace std;

int main(){
	char a[5] = {'h','e','l','l','o'}; //char array style declaration
	char b[6] = "world";	//string style declaration, which always end by a null character ('\o') implicitly
	string str = "lol";		//standard string style declaration, actually is a dynamic length character array
  
	cout<<a<<" "<<b<<endl;	//output hello world
	cout<<str<<endl;		//output lol
	
  //output hello in vertical
    for (int i=0; i<5; i++){
		cout<<a[i]<<endl;	
	}
  
  //output world in vertical
	for (int i=0; i<5; i++){
		cout<<b[i]<<endl;	
	}
  
  //output lol in vertical
	for (int i=0; i<5; i++){
		cout<<str[i]<<endl;	
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
//declare integer x, let's assume its adress is 0x123456
int x = 10;	

//define integer y have same address as x, 0x123456, which mean x and y always have same value. 
int& y = x;	

//display the value of y, which mean display the value stored in 0x123456 which is 10
cout<<y<<endl; 	

//set value of x to 20, which mean set the value stored in 0x123456 to 20
x = 20;	

//display the value of y, which mean display the value stored in 0x123456 which is 20
cout<<y<<endl;  

//set value of y to 50, which mean set the value stored in 0x123456 to 50
y = 50; 

//display the value of x, which mean display the value stored in 0x123456 which is 50
cout<<x<<endl;	
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
cout<<&x<<endl; //output: 0x123456

//declare a integer pointer pInt pointing to the address of x, which is 0x123456
int* pInt = &x;

//output the value of pInt, which is 0x123456
cout<<pInt<<endl; //output: 0x123456

//output the value of pointee of pInt, which means printing the value in address 0x123456, which is 12
cout<<*pInt<<endl; //output: 12

//change the value of x, which mean changing the value in address 0x123456
x = 24;

//output the value of pointee of pInt, which means printing the value in address 0x123456, which is 24
cout<<*pInt<<endl;	//output: 24

//change the value of pointee of pInt to 48, which means changing the value in address 0x123456 to 48
*pInt = 48;

//print out the value of x, which means printing the value on 0x123456, which is 48
cout<<x<<endl;	//output: 48
```

Note: To declare a pointer with no initial pointee, we can use `NULL` (C style) or `nullptr` (c++0x style). Both of them meaning a pointer pointing to nothing. 

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
cout<<a<<" "<<b<<endl; //10 3
```



##### Array as a Pointer

Array is actually a pointer pointing to its first element, and a string is actually a character pointer pointing to the first character. For example:

```C++
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
cout<<int_array<<endl; //print the address of first element
cout<<*int_array<<endl; //print the value of first element, which is 0

char buff[12]="hello world";
cout<<*buff<<endl;	//print out h
```

##### Memory offset

If we plus or minus some value with the pointer, we can access its neighbor, and this is how array works.

```C++
int int_array[10]={0,1,2,3,4,5,6,7,8,9};
cout<<int_array<<" "<<*int_array<<endl;			//0x100000 0
cout<<int_array+1<<" "<<*(int_array+1)<<endl;	//0x100004 1
cout<<int_array+2<<" "<<*(int_array+2)<<endl;	//0x100008 2
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

Enum is actually using numbers to represent different non-numerical values. Maybe an example will be clearer.

```C++
enum robotics_subteam = {kRoboCon, kRov, kSmartCar};
cout<<kRoboCon<<endl;	//output: 0
cout<<kRov<<endl;		//output: 1
cout<<kSmartCar<<endl;	//output: 2
```

In the above case, we are actually using 0 to represent RoboCon, 1 to represent ROV, 2 to represent smart car. 

We can also change the data type stored in enum (but must still be integer) and change the value stored in the element in enum:

```C++

```

