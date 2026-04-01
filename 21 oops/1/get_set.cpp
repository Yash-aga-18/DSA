#include <bits/stdc++.h>
using namespace std;

class Hero {
private:
    int age;

public:
    Hero() {
        age = 18;   // default / permanent value
    }

    void setAge(int a) {            // setter
        if (a >= 0 && a <= 120) {
            age = a;
        }
    }

    int getAge() const {            // getter
        return age;
    }


};


void func() {

    Hero h1;

    cout << h1.getAge();   // ✅ prints 18
}


int main() {

    Hero h;

    cout << h.getAge();    // 18    

    h.setAge(99);
    cout << h.getAge();    // 99

    func();

 return 0;

}
