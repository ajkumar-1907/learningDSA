// Inheritance is a mechanism in C++ where one class (derived class) inherits 
// properties and behaviors (methods) from another class (base class).

#include<iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating." << endl;
    }

    void sleep() {
        cout << "Animal is sleeping." << endl;
    }
};

// Derived class inheriting from Animal
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog is barking." << endl;
    }
};

int main() {
    Dog d;

    // Dog object can access both its own and inherited functions
    d.eat();      // Inherited from Animal
    d.sleep();    // Inherited from Animal
    d.bark();     // Own function

    return 0;
}
