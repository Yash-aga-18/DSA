#include <iostream>
using namespace std;

class Animal {
public:
    
    void sound() {
        cout << "Animal makes sound" << endl;
    }

    // virtual void sound() {       // this is the correct
    //     cout << "Animal makes sound" << endl;
    // }
};

class Dog : public Animal {
public:

    void sound() {
        cout << "Dog barks" << endl;
    }
};

int main() {

    Dog d;

    d.sound();          // calls Dog's sound()
    d.Animal::sound();  // ✅ calls Animal's sound()

    return 0;
}
/*
Explanation:

Function name same → sound()
Child overrides parent’s function
Base class pointer → child object
Function call decided at run time
virtual keyword is mandatory

*/
