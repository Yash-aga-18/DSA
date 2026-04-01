#include <bits/stdc++.h>
using namespace std;

// -------------------- Parent Class --------------------
class Human {

 protected:
    int age;                // protected data member

    void setAge(int a) {    // protected member function
        age = a;
    }

    void getAge() {         // protected member function
        cout << age << endl;
    }

 public:
    Human(int a) {          // public constructor
        age = a;            // allowed (same class)
    }

};


// -------------------- Public Inheritance --------------------
class Male : public Human {
public:
    Male(int a) : Human(a) {}

    void show() {
        setAge(20);         // ✅ allowed (protected → accessible in derived)
        getAge();           // ✅ allowed
    }

    void attack() {
        cout << "Attacking" << endl;
    }
};


// -------------------- Private Inheritance --------------------
class Female : private Human {
 
 public:
    Female(int a) : Human(a) {}

    void show() {
        setAge(30);         // ✅ allowed (protected inside derived)
        getAge();           // ✅ allowed
    }

    void attack() {
        cout << "Attacking" << endl;
    }
};

// -------------------- Protected Inheritance --------------------
class Others : protected Human {
 
 public:
    Others(int a) : Human(a) {}

    void show() {
        setAge(40);         // ✅ allowed (protected inside derived)
        getAge();           // ✅ allowed
    }

    void attack() {
        cout << "Attacking" << endl;
    }
};


int main() {

    Male m(10);
    Female f(15);
    Others o(18);

    // ❌ NOT allowed (protected members)
    // m.setAge(25);
    // f.getAge();
    // o.setAge(35);

    // ✅ Access only through derived class public methods
    m.show();
    m.attack();

    f.show();
    f.attack();

    o.show();
    o.attack();

    return 0;

}

/*
Human (protected age)

public inheritance     → age stays protected
protected inheritance  → age stays protected
private inheritance    → age becomes private



*/
