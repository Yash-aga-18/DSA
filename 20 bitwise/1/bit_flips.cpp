#include <bits/stdc++.h>
using namespace std;

// count no. of flips required to convert a number to desired goal


int main()
{
    int num1 = 10;
    int num2 = 7;

    int temp = num1 ^ num2;


    int count = 0;
    while(temp>0){
        temp = (temp & (temp-1) );
        count++;
    }

    cout<<count<<" flips required";
    

 return 0;

}

/*

10 --> 1010
7  --> 0111

We required 3 bits flipped to change 10 to 7

doing XOR give 1 on those places which are different
after that we count those set bits 

*/