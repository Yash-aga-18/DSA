#include <iostream>
using namespace std;

// Parent class
class Animal {
public:
    void sound() {
        cout << "Animal sound" << endl;
    }
};

// Child class
class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    
    Dog d;
    d.sound();   // inherited from Animal
    d.bark();    // Dog's own function

    return 0;
}
