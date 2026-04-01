#include <bits/stdc++.h>
using namespace std;

class Hero {

 private:
    int health;
    int age;

 public:

    Hero(int h) {
        health = h;
        age = 50;
    }

    Hero(Hero &temp){   // always pass by reference   otherwise it stucks in loop

        this->health = temp.health;
        // this->age = temp.age;    // we here not make copy of age so it gives default value
    }

    int getHealth() {
        return health;
    }
    
    int getAge() {
        return age;
    }

};

int main() {

    Hero h1(100);
    Hero h2(h1);     // user defined constructor

    cout << h1.getHealth()<< endl;
    cout << h1.getAge()<< endl;
    
    cout << h2.getHealth()<< endl;
    cout << h2.getAge()<< endl;


 return 0;

}