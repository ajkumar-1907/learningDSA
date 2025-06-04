#include<iostream>

using namespace std;

class Engine{
public:
    void powerOn() {
        cout << "Engine is on..." << endl;
    }
};

class Vehicle : public Engine{
public:
    void start() {
        cout << "Vehicle starting..." << endl;
    }
};

class Car{
public:
    void drive() {
        cout << "Car is driving..." << endl;
    }
};

// Hybrid: SportsCar inherits from both Vehicle (multilevel) and Car (multiple)
class SportsCar : public Vehicle, public Car{
public:
    void turbo(){
        cout << "Turbo boost!" << endl;
    }
};

int main() {
    SportsCar sc;
    sc.powerOn();  // From Engine
    sc.start();    // From Vehicle
    sc.drive();    // From Car
    sc.turbo();    // Own method

    return 0;
}
