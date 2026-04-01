#include <bits/stdc++.h>
using namespace std;

// -------------------- Parent Class --------------------
class Human {

 private:
    int age;          // private data member

    void setAge(int a) {   // private member function
        age = a;
    }

    void getAge() {        // private member function
        cout << age << endl;
    }

 public:
    // public constructor to initialize private data
    Human(int a) {
        age = a;          // allowed (same class)
    }
};


// -------------------- Public Inheritance --------------------
class Male : public Human {
public:
    Male(int a) : Human(a) {}   // constructor calls base constructor

    void attack() {
        cout << "Attacking" << endl;
    }

    void test() {
        // setAge(20);   ❌ NOT allowed (private in Human)
        // getAge();     ❌ NOT allowed (private in Human)
    }
};


// -------------------- Private Inheritance --------------------
class Female : private Human {
public:
    Female(int a) : Human(a) {}

    void attack() {
        cout << "Attacking" << endl;
    }

    void test() {
        // setAge(30);   ❌ NOT allowed (private in Human)
        // getAge();     ❌ NOT allowed (private in Human)
    }
};


// -------------------- Protected Inheritance --------------------
class Others : protected Human {
public:
    Others(int a) : Human(a) {}

    void attack() {
        cout << "Attacking" << endl;
    }

    void test() {
        // setAge(40);   ❌ NOT allowed (private in Human)
        // getAge();     ❌ NOT allowed (private in Human)
    }
};


int main() {

    Male m(20);
    Female f(30);
    Others o(40);

    m.attack();   // ✅ allowed
    f.attack();   // ✅ allowed
    o.attack();   // ✅ allowed

    // m.setAge(25); ❌ NOT allowed (private in Human)
    // f.setAge(35); ❌ NOT allowed
    // o.setAge(45); ❌ NOT allowed

    return 0;
}

// private base members are never inherited
// Only the base class itself can access its private members