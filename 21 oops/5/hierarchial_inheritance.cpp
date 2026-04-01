#include <iostream>
using namespace std;

// Parent class
class Vehicle {
public:
    void type() {
        cout << "Vehicle" << endl;
    }
};

// Child class 1
class Car : public Vehicle {
public:
    void show() {
        cout << "Car" << endl;
    }
};

// Child class 2
class Bike : public Vehicle {
public:
    void show() {
        cout << "Bike" << endl;
    }
};

int main() {
    
    Car c;
    c.type();   // inherited from Vehicle

    Bike b;
    b.type();   // inherited from Vehicle

    return 0;
}
