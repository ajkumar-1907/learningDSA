#include<iostream>
using namespace std;

class Engine {
public:
    void powerOn() {
        cout << "Engine is powering on..." << endl;
    }
};

class Wheels {
public:
    void rotate() {
        cout << "Wheels are rotating..." << endl;
    }
};

class Car : public Engine, public Wheels {
public:
    void drive() {
        cout << "Car is driving..." << endl;
    }
};

int main() {
    Car c;
    c.powerOn();  // From Engine
    c.rotate();   // From Wheels
    c.drive();    // Own method
    return 0;
}
