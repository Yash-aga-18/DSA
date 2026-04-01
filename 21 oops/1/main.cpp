#include <bits/stdc++.h>
#include "hero.cpp"     // calling the class stored in another file
using namespace std;

class Hero1{        // we can make the class like this
//                  this is empty class

};  

class Hero2{        // we can make as many classes
 
 public :

    int health = 10;
    char level;

    void get_health(){
        cout<<health;
    }

};  




int main()
{
    
    Hero  h;
    Hero1 h1;
    Hero2 h2;

    cout<<"size--> "<<sizeof(h) <<endl;
    cout<<"size--> "<<sizeof(h1) <<endl;
    cout<<"size--> "<<sizeof(h2) <<endl;
        

 return 0;

}
/*

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
What the compiler actually does:

#include "hero.cpp" means:
👉 The compiler copies the entire content of hero.cpp
👉 Pastes it inside main.cpp before compilation
So effectively, the compiler sees one single file



this is still WRONG practice
1️⃣ Breaks separate compilation

C++ is designed for:

Multiple .cpp files
Compiled separately
Linked together
Including .cpp defeats this design.

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

h1 size --> is 1 as it is empty class

h2 size --> 

should be 4+1 (int+char) = 5
as member function doesnt occupy space

but it is 8 because of padding and grredy alignment




*/