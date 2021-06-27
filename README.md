# Meta-Objects-in-Cpp

## Introduction
C++ is a strongly typed language and all classes must be known at compile-time. It does not let you define new classes or modify the existing classes during runtime. It does not let you query information such as attributes of the given class and values of attributes of the given object. This information about the attributes of the class and values of the objects is known as meta-information. 

Languages like CLOS and Smalltalk provide such features. In C++, this information is captured in the class definition of the object, so the class is a meta-object at development time but not at runtime. 
This project attempts to provide such features by implementing Meta-Object-Protocol in C++, thus allowing the definition of classes at runtime and querying the information about classes and objects. 

## Operations supported
* Defining new classes
* Adding attributes to classes
* Querying attributes of classes
* Creating objects of classes
* Querying the class of an object
* Setting attribute values of an object
* Querying attribute values of an object
* Deleting objects  

## Implementation

### Class Diagram

![](/img/class_diagram.jpeg)

## Usage
Go to the `src` folder and run the following commands in the terminal to execute one of the example files

```
$ g++ -c ../examples/reflection.cpp type.cpp class_definition.cpp object.cpp attribute.cpp
$ g++ reflection.o type.o class_definition.o object.o attribute.o
$ ./a.out 
```




