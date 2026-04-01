#include <bits/stdc++.h>
using namespace std;

class Hero {

public:
    int health;

    // static const data member
    static const int maxHealth;   // belongs to CLASS

    Hero(int h) {
        health = h;
    }
};

// definition + initialization (outside class)
const int Hero::maxHealth = 100;

int main() {

    Hero a(50);
    Hero b(80);

    cout << a.health << endl;           // 50
    cout << b.health << endl;           // 80

    // Access static const member (recommended way)
    cout << Hero::maxHealth << endl;    // 100

    // Allowed but NOT recommended
    cout << a.maxHealth << endl;        // 100
    cout << b.maxHealth << endl;        // 100

    // Hero::maxHealth = 200;   // ❌ ERROR: const value

    return 0;
}
