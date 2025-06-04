#include<iostream>

using namespace std;

//base class
class Vehicle{
public:
    void start() {
        cout << "Vehicle is starting..." << endl;
    }
};

// Derived class (inherits from Vehicle)
class Car : public Vehicle {
public:
    void drive() {
        cout << "Car is driving..." << endl;
    }
};

int main() {
    Car myCar;

    //accessing base class function using derived class object
    myCar.start();   // inherited from Vehicle
    myCar.drive();   // defined in Car

    return 0;
}
