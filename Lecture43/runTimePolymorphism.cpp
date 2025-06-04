// Run-Time Polymorphism:
//      At runtime, the function call is resolved based on the actual object type, not the pointer type.


#include<iostream>

using namespace std;

class Animal{
public:
    virtual void sound(){  // virtual function
        cout << "Animal makes sound" << endl;
    }
};

class Dog : public Animal{
public:
    void sound() override{
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal{
public:
    void sound() override{
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a;  // Base class pointer

    Dog d;
    Cat c;

    a = &d;
    a->sound();  // Output: Dog barks (runtime polymorphism)

    a = &c;
    a->sound();  // Output: Cat meows (runtime polymorphism)

    return 0;
}
