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

    int getHealth() {
        return health;
    }
    
    int getAge() {
        return age;
    }

};

int main() {

    Hero h1(100);
    Hero h2(h1);     // it is default copy constructor
    Hero h3 = (h1);     // it is default copy constructor

    cout << h1.getHealth()<< endl;
    cout << h1.getAge()<< endl;
    
    cout << h2.getHealth()<< endl;
    cout << h2.getAge()<< endl;
    
    cout << h3.getHealth()<< endl;
    cout << h3.getAge()<< endl;

 return 0;

}