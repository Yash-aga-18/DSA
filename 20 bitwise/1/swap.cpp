#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int a = 5;
    int b = 3;

    // Step 1:
    // a = a ^ b
    // a now stores (original a XOR original b)
    a = a ^ b;

    // Step 2:
    //    b = a  ^ b
    // = (a ^ b) ^ b
    // = a   (because b ^ b = 0 and a ^ 0 = a)
    b = a ^ b;

    // Step 3:
    //   a  = a  ^ b
    // = (a ^ b) ^ a
    // = b   (because a ^ a = 0 and b ^ 0 = b)
    a = a ^ b;

    // After these steps: a and b are swapped

    cout<<" a = "<<a<<endl;
    cout<<" b = "<<b;


 return 0;

}