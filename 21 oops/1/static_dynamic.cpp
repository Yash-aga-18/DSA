#include <bits/stdc++.h>
using namespace std;

class Hero {

    // properties
private:
    int health;
    char level;

public:

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


void static_func() {     // static allocation

    Hero a;

    a.setHealth(80);
    a.setLevel('B');

    cout << "level is " <<  a.getLevel() << endl;
    cout << "health is " << a.getHealth() << endl;
}


void dynamic_func(){     // dynamically allocation
    
    Hero *b = new Hero;

    b->setLevel('A');
    b->setHealth(70);

    cout << "level is " <<  (*b).getLevel() << endl;
    cout << "health is " << (*b).getHealth() << endl;

    cout << "level is " <<  b->getLevel() << endl;
    cout << "health is " << b->getHealth() << endl;

    delete b;

}

void dynamic_func1(){     // dynamically allocation
    
    Hero a;

    Hero *b = &a;

    // (*b).setHealth(40);  // we can also write like this
    
    b->setLevel('A');       // we prefer this
    b->setHealth(70);

    cout << "level is " <<  (*b).getLevel() << endl;
    cout << "health is " << (*b).getHealth() << endl;

    cout << "level is " <<  b->getLevel() << endl;
    cout << "health is " << b->getHealth() << endl;

    delete b;

}


int main()
{
    
    static_func();

    dynamic_func();


 return 0;

}