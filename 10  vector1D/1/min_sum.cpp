#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2160     Minimum Sum of Four Digit Number After Splitting Digits
// Input: num = 2932
// Output: 52
// Explanation: Some possible pairs [new1, new2] are [29, 23], [223, 9], etc.
// The minimum sum can be obtained by the pair [29, 23]: 29 + 23 = 52.


int main()
{

    int num;
    cout<<"enter a 4 digit number"<<endl;
    cin>>num;

    int v[4];

    for (int i = 0; i < 4; i++) {

        v[i] = num % 10;
        num /= 10;
    }

    sort(v, v+4);

    int sum =  (v[0]*10+v[2]) + (v[1]*10+v[3]);
    cout<<"min sum is --> "<<sum;

    return 0;
}