#include <bits/stdc++.h>
using namespace std;

class Hero {

private:
    int health;
    char level;

public:
   
    Hero() {        //  constructor

        cout << "public me likha h" << endl;
        health = 100;
        level = 'A';

    }


    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }

};


int main() {

    Hero a;   // ✅ constructor called automatically

    cout << a.getHealth();


 return 0;

} 

//   Constructor always have same name as class

