#include <bits/stdc++.h>
using namespace std;

class Hero {

 private:
    int health;
    char level;

 public:
    Hero(int h) {     // parameterized constructor
        health = h;
    }

    Hero(int h, char l) {     // parameterized constructor
        health = h;
        level = l;
    }

    Hero() {}               // we created for having no parameters

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

};



int main() {
    
    Hero h1(80);                 // values passed at creation
    cout << h1.getHealth()<<endl;
    
    Hero h2(90, 'A');          // values passed at creation
    cout << h2.getHealth() << " " << h2.getLevel()<<endl;


    Hero h3;      // it is not valid as there is no constructer taking no parameters untilwe make it



 return 0;

}