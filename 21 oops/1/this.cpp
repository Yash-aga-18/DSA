#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    int health;

public:

    Hero(int health) {      
        // health = health;     // it causes ambiguity results in no changes
        this -> health = health;
        cout<< (&this-> health) <<endl;
    }

    int getHealth() {
        cout<<  this->health<< endl;
        return health;
    }
    
};


int main() {
    
    Hero h(50);
    cout<< &h <<endl;         
    
    cout << h.getHealth();

}

/*
(&this-> health) == &h
*/
