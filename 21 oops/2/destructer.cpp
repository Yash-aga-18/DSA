#include <bits/stdc++.h>
using namespace std;

class Hero {
public:
    char* name;

    Hero() {
        name = new char[100];
        cout<<"constructer called "<<endl;
    }
    
    ~Hero() {
        delete[] name;
        cout<<"destructer called "<<endl;
    }
};


int main() {

    Hero hero1;             // dest. called automatically

    Hero *b = new Hero();   // required to call dest. manually

    delete b;               // this is the manual we done for dynamic



    return 0;
}
