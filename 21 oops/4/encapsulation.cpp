#include <bits/stdc++.h>
using namespace std;

class Student {

    string name;
    int age;
    int height;

 public:
    
    int getAge() {
        return age;
    }

    void setAge(int a) {
        age = a;
    }


};

int main()
{
    
    Student first;
    first.setAge(18);           // controlled write
    cout << first.getAge();     // controlled read


 return 0;

}
/*

Why this is Encapsulation ✅
1️⃣ Data Members are PRIVATE (Data Hiding)
    string name;
    int age;
    int height;


    ➡️ These are private by default
    ➡️ You cannot access them directly from main()

    ❌ This is NOT allowed:

    Student s;
    s.age = 20;   // ❌ ERROR

    This is data hiding → 1st pillar of encapsulation

2️⃣ Access is Controlled using PUBLIC functions
   
    int getAge()
    void setAge(int a)

    ✔ You can read data → getAge()
    ✔ You can modify data → setAge()

    This is controlled access → 2nd pillar of encapsulation

3️⃣ Usage in main()

    first.setAge(18);           // controlled write
    cout << first.getAge();     // controlled read

    ➡️ User cannot touch age directly
    ➡️ Must go through class methods


🔹 Interview-Ready Explanation (Say This)
“Encapsulation is achieved by making data members private and providing public getter and setter functions to access and modify them.
In this code, age, name, and height are hidden, and access to age is controlled through getAge() and setAge().”

*/