#include <bits/stdc++.h>
using namespace std;


class Hero {

 public:
    int health;           // normal data member
    const int power;      // const data member (value fixed per object)

    /*
    Constructor
    - const data member MUST be initialized
    - initializer list is mandatory
    */

    Hero(int h, int p) : power(p) {
        health = h;
    }

    /*
    const member function
    - promises NOT to modify object data
    - can be called on const objects
    */
    int getHealth() const {

        // health = 100;   // ❌ ERROR: modification not allowed
        return health;     // ✅ read-only access
    }

    /*
    non-const member function
    - can modify object data
    - cannot be called on const objects
    */
    void setHealth(int h) {
        health = h;        // ✅ allowed
        // power = h;      // ❌ ERROR
    }

    /*
   
    void setPower(int p) {   ❌ Not allowed because power is const
        power = p;
    }

    */

};

int main() {

    Hero a(100, 50);

    cout << "Health: " << a.getHealth() << endl;
    cout << "Health: " << a.health << endl;
    cout << "Power : " << a.power << endl;

    a.setHealth(200);      // ✅ allowed
    cout << a.getHealth() << endl;
    // a.power = 60;       // ❌ ERROR: power is const



    const Hero b(80, 40);   // Const Object

    cout << b.getHealth() << endl;   // ✅ allowed (const function)
    // b.setHealth(90);    // ❌ ERROR: non-const function
    // b.power = 60;       // ❌ ERROR: const data member

    return 0;
}

/*
----------------------------------------
            FINAL SUMMARY
----------------------------------------

const int power;
→ const data member
→ once initialized, value can never change per object

int getHealth() const;
→ const member function
→ cannot modify object data

const Hero b(...);
→ const object
→ can call ONLY const member functions

----------------------------------------
*/
