#include <bits/stdc++.h>
using namespace std;

class Human {

 public:
    
    int age;

    void setAge(int a) {
        age = a;
    }

    void getAge() {
        cout<<age<< endl;
        cout<<this->age;

    }


};


class Male : public Human {

 public:

    string color;

    void attack() {
        cout <<"Attacking"<< endl;
    }

};

int main() {

    Male m;
    m.setAge(20);     // inherited function
    m.getAge();      // accessing inherited data
    m.attack();


    return 0;
}
