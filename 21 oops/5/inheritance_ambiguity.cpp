#include <iostream>
using namespace std;

// Parent1
class A {
public:
    void show() {
        cout << "Class A" << endl;
    }

    void speaks() {
        cout << "Class A speaks" << endl;
    }

};


// Parent2
class B {
public:
    void show() {
        cout << "Class B" << endl;
    }

    void speaks(int x) {
        cout << "Class B speaks" << endl;
    }

};


// Child (Multiple Inheritance)
class C : public A, public B {

};



int main() {
    C obj;

    // obj.show();      // it is ambiguity as  both parent have same func name

    obj.A::show();   // calls show() of class A
    obj.B::show();   // calls show() of class B (if needed)

    

    // obj.speaks();    // it doesn't removes the ambiguity
    // obj.speaks(10);  // it doesn't removes the ambiguity

    return 0;
}

/*

We remove the ambiguity by -->  Scope resolution operator(::)

❌ Changing argument types does NOT remove ambiguity    
*/
