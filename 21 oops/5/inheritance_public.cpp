#include <bits/stdc++.h>
using namespace std;

// -------------------- Parent Class --------------------
class Human {

 public:
    int age;

    void setAge(int a) {
        age = a;
    }

    void getAge() {
        cout<<age<< endl;
    }


};


// -------------------- Public Inheritance --------------------
class Male : public Human {
public:
    void attack() {
        cout << "Attacking" << endl;
    }
};


// -------------------- Private Inheritance --------------------
class Female : private Human {
public:
    void attack() {
        cout << "Attacking" << endl;
    }

};


// -------------------- Protected Inheritance --------------------
class Others : protected Human {
public:
    void attack() {
        cout << "Attacking" << endl;
    }

    // ✅ PUBLIC WRAPPER to access protected members
    void setOtherAge(int a) {
        setAge(a);          // allowed (protected inside derived)
    }

    void showOtherAge() {
        getAge();           // allowed (protected inside derived)
    }
};



int main() {

    Male   m;
    Female f;
    Others o;


    // -------- Male object --------
    m.setAge(20);     // ✅ ALLOWED: public inheritance keeps functions public
    m.getAge();       // ✅ ALLOWED
    m.attack();       // ✅ ALLOWED


    // -------- Female object --------
    // f.setAge(30);     // ❌ ERROR: setAge() became PRIVATE due to private inheritance
    // f.getAge();       // ❌ ERROR: getAge() is PRIVATE in Female
    f.attack();       // ✅ ALLOWED (attack is Female's own public function)


    // -------- Others object --------
    // o.setAge(40);     // ❌ ERROR: setAge() is PROTECTED due to protected inheritance
    // o.getAge();       // ❌ ERROR: getAge() is PROTECTED
    
    o.setOtherAge(40);   // ✅ allowed via wrapper
    o.showOtherAge();    // ✅ allowed via wrapper
    o.attack();
    
    
  return 0;

}
