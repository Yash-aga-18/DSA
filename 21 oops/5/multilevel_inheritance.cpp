#include <iostream>
using namespace std;

// Class A (Base class)
class A {
public:
    void msg() {
        cout << "Class A" << endl;
    }
};

// Class B (Derived from A)
class B : public A {
public:
    void message() {
        cout << "Class B" << endl;
    }
};

// Class C (Derived from B)
class C : public B {
public:
    void finalMsg() {
        cout << "Class C" << endl;
    }
};

int main() {
    C c;
    c.msg();       // from class A
    c.message();   // from class B
    c.finalMsg();  // from class C

    return 0;
}
