#include <iostream>
using namespace std;

// Parent1
class A {
public:

    void speaks() {
        cout << "speaks" << endl;
    }

    void show() {
        cout << "Class A" << endl;
    }

};


// Parent2
class B {
public:

    void barks() {
        cout << "barks" << endl;
    }

    void show() {
        cout << "Class B" << endl;
    }
};


// Child (Multiple Inheritance)
class C : public A, public B {

};



int main() {
    C obj;

    obj.speaks();   // inherited property from A
    obj.barks();    // inherited property from B



    // obj.show();      // it is ambiguity as  both parent have same func name

    obj.A::show();   // calls show() of class A
    obj.B::show();   // calls show() of class B (if needed)

    return 0;
}
