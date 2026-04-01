#include <bits/stdc++.h>
using namespace std;

class Hero {

 protected:
    int power = 10;

};


class SuperHero : public Hero {

 public:
    void showPower() {
        cout << power<<endl;   // ✅ allowed (child class)
    }
    int age = 100;

};


int main() {

    SuperHero s;

    // cout << s.power; ❌ ERROR
    s.showPower();
    cout << s.age; 


}
