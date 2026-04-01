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

    // deep copy constructor
    Hero(const Hero& temp) {
            
        this->name = new char[strlen(temp.name) + 1];
        strcpy(this->name, temp.name);
    }


    ~Hero() {       // it is deconstructor
        delete[] name;
    }
};



int main() {
    
    Hero h1;
    h1.setName("Ironman");

    Hero h2(h1);   // ✅ deep copy
    
    cout << h1.name << endl;  // Ironman
    cout << h2.name << endl;  // Ironman
    
    
    h1.name[0] = 'X';

    cout << h1.name << endl;  // Xronman
    cout << h2.name << endl;  // Ironman


 return 0;

}

/*
h1.name ──> "Ironman"
h2.name ──> "Ironman"


*/