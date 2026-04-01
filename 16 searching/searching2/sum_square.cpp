#include <bits/stdc++.h>
using namespace std;

// leetcode Q->633    Sum of Square Numbers
// eg--> 5 is perfect sqr no. as (1*1 + 2*2 = 5)


int main() {

    int c = 5;

    long long x = 0;
    long long y = sqrt(c);

    while (x <= y) {

        long long val = x*x + y*y;

        if (val == c) {
            cout<<x<<" "<<y;
            cout<<endl;
            cout << "true";
            return 0;
        }

        if (val < c)    x++;
        else            y--;
    }

    cout << "false";
    
    return 0;
}
