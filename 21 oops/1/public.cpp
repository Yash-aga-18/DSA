#include <bits/stdc++.h>
using namespace std;

class Hero {

  private:
    int level = 100;
 
  public:
    int age = 70;

};


void func(){
    
    Hero h;
    cout <<h.age <<endl;    // gives 70 because of object independence
}



int main() {

    Hero h,h1;

//    cout<<h.level;       //  we can not use it as it is private

    h.age = 18;              // ✅ allowed
    cout <<h.age <<endl;     // ✅ gives new updated value 18
    cout <<h1.age <<endl;    // ✅ gives new updated value 18

    func();


}
/*

Object independence (VERY IMPORTANT)
Hero h;   // object in main
Hero h;   // object in func


These are two DIFFERENT objects.

So:
h.age = 18; in main()
does NOT affect h.age inside func()

*/