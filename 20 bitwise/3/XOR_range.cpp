#include <bits/stdc++.h>
using namespace std;

// give me XOR of the no between the range(inclusive the numbers)

int xorUpto(int num){  // from observing the pattern

    if (num % 4 == 1) return 1;
    if (num % 4 == 2) return num + 1;
    if (num % 4 == 3) return 0;
    if (num % 4 == 0) return num;

    return -1;

}


int main()
{
    int num1 = 3;
    int num2 = 7;

    int result = xorUpto(num2) ^ xorUpto(num1 - 1);

    cout<<result;
    


 return 0;

}

/*
1--> 1                   1
2--> 1^2                 3
3--> 1^2^3               0
4--> 1^2^3^4             4

5 → 1^2^3^4^5            1
6 → 1^2^3^4^5^6          7
7 → 1^2^3^4^5^6^7        0
8 → 1^2^3^4^5^6^7^8      8



*/