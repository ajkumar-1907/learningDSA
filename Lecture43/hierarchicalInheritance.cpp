#include<iostream>
using namespace std;

class Vehicle {
public:
    void start() {
        cout << "Vehicle is starting..." << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving..." << endl;
    }
};

class Bike : public Vehicle {
public:
    void ride() {
        cout << "Bike is riding..." << endl;
    }
};

int main() {
    Car c;
    c.start();  // From Vehicle
    c.drive();  // Car’s method

    Bike b;
    b.start();  // From Vehicle
    b.ride();   // Bike’s method

    return 0;
}
