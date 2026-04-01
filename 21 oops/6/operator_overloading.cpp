#include <iostream>
using namespace std;

class B {
public:
    int a;
    int b;

    int add() {
        return a + b;
    }

    // Operator overloading of +
    // This function is called when obj1 + obj2 is written
    void operator+(B &obj) {

        // 'this' points to the left-hand object (obj1)
        int value1 = this->a;

        // obj refers to the right-hand object (obj2)
        int value2 = obj.a;

        // Custom behavior of + operator
        // Instead of addition, we perform subtraction
        cout << "Output = " << value2 - value1 << endl;
    }
};

int main() {
    B obj1, obj2;

    // Assign values
    obj1.a = 4;
    obj2.a = 7;

    // Calls operator+ function
    // obj1 + obj2  → obj1.operator+(obj2)
    obj1 + obj2;

    return 0;
}


/*
Explanation:

+ normally adds numbers
Here it subtarcats numbers
Compiler resolves this at compile time


What Happens Internally (Very Important)

When you write: obj1 + obj2;

The compiler converts it to:    obj1.operator+(obj2);

this->a → obj1.a → 4
obj.a → obj2.a → 7

Output: 3

📌 Key Points

Operator function name:

operator+
this pointer refers to calling object
Operator behavior can be redefined
Return type can be void or an object (depending on need)

⚠️ Important Note

Overloading does not change operator precedence
Some operators cannot be overloaded (::, ., sizeof, ?:)

*/