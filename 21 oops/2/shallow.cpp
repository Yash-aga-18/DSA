#include <bits/stdc++.h>
using namespace std;

class Hero {
public:
    char* name;

    Hero() {
        name = new char[100];
    }

    void setName(const char name[]) {
        strcpy(this->name, name);
    }
    // NO copy constructor written
};


int main() {
    
    Hero h1;
    h1.setName("Ironman");
    
    Hero h2(h1);    //  shallow copy
//  Hero h2 = h1;   //  shallow copy
    

    cout << h1.name << endl;
    cout << h2.name << endl;

    h1.name[0] = 'X';

    cout << h1.name << endl;  //  changed
    cout << h2.name << endl;  //  also changed


 return 0;

}

/*

h1.name ──┐
          ├──> "Ironman"
h2.name ──┘

*/