#include <bits/stdc++.h>
using namespace std;

class Hero {

public:
int health;
    Hero() {          // default constructor

        cout<<"in default " <<&health<<endl;
    }

    int age;

    int getHealth() {
        return health;
    }

};


void func(){

    Hero h1;           // default constructor called
    
    cout<<"in funcn "<< &h1<< endl;
    cout<<"in funcn "<< &h1.health<< endl;
}


int main() {
    
    Hero h;           // default constructor called
    
    cout<< "in main "<<&h<< endl;
    cout<< "in main "<<&h.health<< endl;

    func();


}
/*
 health and h have the same address because health is the FIRST data member of the object.
 age does not, so its address is offset from the object start.
*/