#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    int health;

public:
    
    int getHealth() {
        health = 100;   // ✅ allowed
        return health;  // ✅ allowed
    }
};



int main() {

    Hero h;
    cout<< h.getHealth();   // we can access it as it is public
    
    // cout << h.health; ❌ ERROR
}
