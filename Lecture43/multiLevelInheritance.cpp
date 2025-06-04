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

class SportsCar : public Car {
public:
    void turbo() {
        cout << "Turbo mode activated!" << endl;
    }
};

int main() {
    SportsCar s;
    s.start(); //from Vehicle
    s.drive();  //from Car
    s.turbo();  // Own method
    return 0;
}
