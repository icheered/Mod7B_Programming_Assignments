# Notes for Assignment 3
Templates are pretty cool.

A template class is similar to a class but the arugment types can be assigned at compile time. This means that you can create a class that performs mathematical operations, and you can instantiate it to handle Integers or Doubles or Vectors or Lists without having to create seperate classes for each type.

Template classes are defined as follows:
```cpp
//SomeFile.h
template< typename CLASSTYPE > // Name of the type with which the template is initialized
class ClassName 
{
private:
   CLASSTYPE classProperty; // Property type depends on template type

public:
   // Constructor
   ClassName() : classProperty(initialValue) {/* empty body */}
   // The colon operator indicates the initializer list which sets the initial values of some class parameters. It is identical to defining them in the body.


    // Function declaration
    void insertNode(const CLASSTYPE &value);
    // It uses the type that is defined at class instantiation
}; 
```
```cpp
//main.cpp
#include "SomeFile.h"

int main(){
    ClassName<int> newclass;    // Initialize with type int
    int a = 3;
    newclass.insertNode(a);     // Pass parameter with type int

    return 0;
}
```


### Arrow operator -> 
The arrow operator is a quicker way to do the following:
```cpp
int main(){
    // Lets assume we just have a pointer to an instance (We create it here)
    Entity e;           // Create an instance of an object
    e.data = 3;
    Entity* ptr = &e;   // Create a pointer to the previously instantiated object
    // Lets assume we just have a pointer to an instance (We create it here)

    
    // To access properties of the pointer to an object you first have to dereference it and then access it
    Entity& entity = *ptr;  // Dereference the pointer
    int dat = entity.data;  // Access the parameter Entity.data
    std::cout << dat << std::endl;

    // The arrow operator simplifies this. 
    // It dereferences the pointer and returns the value of the desired parameter
    // It is functionally identical to the 3 lines abov
    std::cout << ptr->data << std::endl;
}

```