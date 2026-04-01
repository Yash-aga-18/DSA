#include <bits/stdc++.h>
using namespace std;

class Hero {

 public:

    int health;
    static int timeToComplete;      // static data member (belongs to class, not object)

    static int printTime() {               // static member function

        //   cout << health;   // ERROR: non-static member

        cout << "Time to complete: " << timeToComplete << endl;
        return timeToComplete;   // can access ONLY static members
    
    }

    static void updateTime(int newTime) {

        timeToComplete = newTime;   // ✅ updating static variable
    
    }

};

// static data member definition (outside class)
int Hero::timeToComplete = 5;


int main() {

    // ✔ Recommended way (class-based access)
    cout << Hero::timeToComplete << endl;
    cout << Hero::printTime() << endl;


    Hero a;
    cout <<"a object value "<< a.timeToComplete << endl;      // Allowed but NOT recommended


    Hero::updateTime(10);     // update static value
    cout<< Hero::printTime();        // 10

  
  return 0;

}
