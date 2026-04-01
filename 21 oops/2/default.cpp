#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    int health;

public:
    Hero() {          // default constructor
        health = 100;
    }

    int age;

    int getHealth() {
        return health;
    }

};

void func(){

    Hero h1;           // default constructor called
    
    cout<<"in funcn "<< &h1<< endl;
}


int main() {
    
    Hero h;           // default constructor called
    
    cout << h.getHealth()<<endl;

    func();


}
/*
 health and h have the same address because health is the FIRST data member of the object.
 age does not, so its address is offset from the object start.
*/