#include <iostream>
using namespace std;

class Math {
 
 public:

    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    // float add(int a, int b, int c) {     // still overloading
    //     return a + b + c;
    // }

    int add(float a, int b, int c) {
        return a + b + c;
    }

};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;      // calls 2-parameter function
    cout << m.add(2, 3, 4) << endl;   // calls 3-parameter function
    return 0;
}
/*
Explanation :

Same function name → add
Different parameters
Compiler decides which function to call



IMP-->
if you just change the type of function, it stills overload 
void add()   to  int add()    it still overloads
You are required to change the argument   either by number of arguments or data type of arguments 

*/