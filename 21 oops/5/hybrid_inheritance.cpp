#include <iostream>
using namespace std;

// Base class A
class A {
public:
    void showA() {
        cout << "Class A" << endl;
    }
};

// Derived class B from A
class B : public A {
public:
    void showB() {
        cout << "Class B" << endl;
    }
};

// Another base class D
class D {
public:
    void showD() {
        cout << "Class D" << endl;
    }
};

// Class C inherits from A and D (Hybrid)
class C : public A, public D {
public:
    void showC() {
        cout << "Class C" << endl;
    }
};

int main() {
    B objB;
    objB.showA();   // from A
    objB.showB();   // from B

    cout << endl;

    C objC;
    objC.showA();   // from A
    objC.showD();   // from D
    objC.showC();   // from C

    return 0;
}
