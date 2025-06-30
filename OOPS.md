# Object-Oriented Programming

## C++ Classes and Objects
Objects and classes are used to wrap related functions and data in one place in C++.

### C++ Class
---
A class is a blueprint for the object.
```
class Room {
	double length;
	double width;
	double height;
	
	    double area(){   
            return length * width;
        }

        double volume(){   
            return length * width * height;
        }
}
```
- length, width and height are data members.
- `area()` and `volume()` are member functions.
---

### C++ Objects
- when a class is created only specifications for object is defined 
- no memory or storage is allocated.
- To use the data and access functions defined in the class, we need to create objects.
- Syntax `ClassName objectName`

```
class Room {
    ...
}

int function(){
    Room roomA, roomB;
}

int main() {
    Room room1, room2, ... ;
}
```

- For accessing data members and member functions we use `.` operator.
- for example `room1.length` and `room1.area()`

```
class Room {
    public:
	    double length;
	    double width;
	    double height;
	
		double area(){   
            return length * width;
        }

        double volume(){   
            return length * width * height;
        }
}

int main() {
	Room room1;
	room1.length = 5.0;
	room1.width = 5.5;
	room1.height = 4.5;
	
	cout << room1.area() << '\n';
	cout << room2.volume() << '\n';
}
```

## C++ Constructors
A constructor is a special member function that is called automatically when an object is created.

A constructor has same name as of class and no return type

A constructor with no parameters is known as a default constructor. 

```
class Floor {
    public:
    // default constructor
        Floor() {
            
        }
}
```
**Note**: If we have not defined any constructor, copy constructor, or move constructor in our class, then the C++ compiler will automatically create a default constructor with no parameters and empty body.

if we want to explicitly declare default constructor
```
class MyClass {
public:
    int x;
    MyClass() = default; // explicitly defaulted constructor
};
```

**To set  default value**

`double length {6.5};`
```
class Room {
	public:
	// default value
	int length {5.5};
	int width {8.5}; 
	int height {4.5};
		// default contructor explicitly
		Room() = default;
		
		double area(){   
            return length * width;
        }

        double volume(){   
            return length * width * height;
        }
}
```

## C++ Member Initializer List
```
Wall(double len, double hgt)
  : length{len}
  , height{hgt} {
}
```

- **order of initialization is depend upon the member variables order.**

if in `class Room` the `double length` then `double height` in order

```
Wall(double len, double hgt)
  : height{hgt},length{len}
  {

  }
```
- **the `length` will be intialize first as it comes first in the order in class no matter what order of intializer list.**


## C++ Copy Constructor
```
class Wall {
  private:
    double length;
    double height;

  public:

    // initialize variables with parameterized constructor
    Wall(double len, double hgt)
      : length{len}
      , height{hgt} {
    }

    // copy constructor with a Wall object as parameter
    // copies data of the obj parameter
    Wall(const Wall& obj)
      : length{obj.length}
      , height{obj.height} {
    }

    double calculateArea() {
      return length * height;
    }
};
```
## default copy constructor
```
#include <iostream>
using namespace std;

// declare a class
class Wall {
  private:
    double length;
    double height;

  public:

    // initialize variables with parameterized constructor
    Wall(double len, double hgt)
      : length{len}
      , height{hgt} {
    }

    double calculateArea() {
      return length * height;
    }
};

int main() {
  // create an object of Wall class
  Wall wall1(10.5, 8.6);

  // copy contents of wall1 to wall2 by default copy constructor
  Wall wall2 = wall1;

  // print areas of wall1 and wall2
  cout << "Area of Wall 1: " << wall1.calculateArea() << endl;
  cout << "Area of Wall 2: " << wall2.calculateArea();

  return 0;
}
```

## C++ Constructor Overloading
```
    // 1. Constructor with no arguments
    Person() {
        age = 20;
    }

    // 2. Constructor with an argument
    Person(int a) {
        age = a;
    }
```
```
// 1. Constructor with no arguments
    Room() {
        length = 6.9;
        breadth = 4.2;
    }

    // 2. Constructor with two arguments
    Room(double l, double b) {
        length = l;
        breadth = b;
    }
    // 3. Constructor with one argument
    Room(double len) {
        length = len;
        breadth = 7.2;
    }
```
## C++ Destructors
A destructor is a special member function that is called automatically when an object goes out of scope or when we delete the object with the delete expression.

In C++, a destructor has the same name as that of the class, and it does not have a return type. `~` precedes the identifier to indicate destructor.

If we don't define any destructor, move assignment, or move constructor in our class, then the C++ compiler will automatically create a default destructor with an empty body. It suffices in most cases.

However, if our class involves resource handling like dynamic memory allocation, we have to define a destructor and deallocate the resources in the destructor body.

The problem comes when your class manages resources that are not automatically cleaned up, such as:

- Raw pointers (new/delete)

- File handles (fopen / fclose)

- Network sockets, mutexes, etc.

- In such cases, you must define a destructor to clean things up.

```
class MyClass {
private:
    int* data;  // raw pointer

public:
    MyClass() {
        data = new int[100];  // dynamically allocated memory
    }
    // No destructor provided
};
```

This compiles fine, and C++ gives you a default destructor. But it does not call delete[] data. So:

Memory leak happens — memory is not freed when the object is destroyed.

This is where you need a custom destructor:
```
~MyClass() {
    delete[] data;  // manually free the memory
}
```

## Dynamic Memory Allocation in Class
When your class has pointer members, and you don’t define a copy constructor, C++ gives you a default copy constructor — but it performs a shallow copy.

Shallow Copy = copying only the pointer value (i.e., address), not the actual data
So two objects will point to the same memory, which causes:

Double deletion (crashes)

Unexpected side effects when one object modifies the other's data

## C++ Access Modifiers
### Types of C++ Access Modifiers
In C++, there are 3 access modifiers:

- public
- private
- protected

**public Access Modifier**
- The `public` keyword is used to create public members (data and functions).
- The public members are accessible from any part of the program.

**private Access Modifier**
- The `private` keyword is used to create private members (data and functions).
- The private members can only be accessed from within the class.
- However, friend classes and friend functions can access private members.
  
```
// define a class
class Sample {

    // private elements
   private:
    int age;

    // public elements
   public:
    void displayAge(int a) {
        age = a;
        cout << "Age = " << age << endl;
    }
};
```
we can only indirectly manipulate the `age` using the `displayAge(int a)` as its public.

**protected Access Modifier**

- The `protected` keyword is used to create protected members (data and function).
- The protected members can be accessed within the class and from the derived class.

| Specifiers | Same Class | Derived Class | Outside Class |
|------------|------------|----------------|----------------|
| public     | Yes        | Yes            | Yes            |
| private    | Yes        | No             | No             |
| protected  | Yes        | Yes            | No             |

**Note:** By default, class members in C++ are private, unless specified otherwise.
