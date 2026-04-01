#include <bits/stdc++.h>
using namespace std;

class Hero {
 
 public:

    int health;
    char level;
    char* name;

    // Default constructor
    Hero() {
        name = new char[100];
    }

    // Setter functions
    void setHealth(int h) {
        health = h;
    }

    void setLevel(char l) {
        level = l;
    }

    void setName(const char name[]) {
        strcpy(this->name, name);
    }

    // Deep Copy Constructor
    Hero(const Hero& temp) {
        name = new char[strlen(temp.name) + 1];
        strcpy(name, temp.name);
        health = temp.health;
        level = temp.level;
    }

    // // Copy Assignment Operator (VERY IMPORTANT)
    // Hero& operator=(const Hero& temp) {

    //     if (this == &temp) {
    //         return *this;
    //     }

    //     delete[] name;

    //     name = new char[strlen(temp.name) + 1];
    //     strcpy(name, temp.name);
    //     health = temp.health;
    //     level = temp.level;

    //     return *this;
    // }


    // Print function
    void print() {
        cout << "Name   : " << name << endl;
        cout << "Health : " << health << endl;
        cout << "Level  : " << level << endl;
        cout << "------------------" << endl;
    }

    // Destructor
    ~Hero() {
        delete[] name;
    }

    
};

int main() {

    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);

   
    Hero hero2(hero1);      // Copy constructor call
//  Hero hero2 = hero1;     // Copy constructor call

    hero1.name[0] = 'G';

    hero1.print();
    hero2.print();

    hero1 = hero2;          // Copy assignment operator call

    hero1.print();
    hero2.print();

    return 0;
}
