// Polymorphism means "many forms". It allows objects of different classes to be treated as 
// objects of a common base class, usually through function overriding or function overloading.


// Commpllie-Time Polymorphism:
// At compile time, the compiler decides which function to call based on arguments


#include<iostream>

using namespace std;

class Print{
public:
    void show(int a){
        cout << "Integer: " << a << endl;
    }

    void show(double d){
        cout << "Double: " << d << endl;
    }

    void show(string s){
        cout << "String: " << s << endl;
    }
};

int main() {
    Print p;
    p.show(5);
    p.show(3.14);
    p.show("Hello");
    return 0;
}
