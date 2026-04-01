#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "Class A" << endl;
    }
};

// class B : public A { };  // this causes the problems
// class C : public A { };  // this causes the problems

class B : virtual public A { };
class C : virtual public A { };


class D : public B, public C { };

int main() {

    D obj;
    // obj.show();   // ❌ Ambiguous if use without virtual

    obj.show();   // No Ambiguous
    
    return 0;

}
/*

Solution: Virtual Base Class

Use the keyword virtual when inheriting the base class.

class B : virtual public A { };
class C : virtual public A { };

This ensures only ONE copy of A exists.
*/


