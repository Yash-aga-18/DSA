#include <bits/stdc++.h>
using namespace std;

// leetcode Q->136 Single Number

// Input: nums = [4,1,2,1,2]
// Output: 4


int main()
{
    
    vector<int>nums = {4,1,2,1,2};

    int ans = 0;
    for (int x : nums) {
        ans ^= x;   // XOR cancels out pairs
    }
    
    cout<< ans;



 return 0;

}

/*
AS XOR give 0 on same values        0^0 = 0    1^1 = 0

0 ^ 4 = 4        (4 on)
4 ^ 1 = 5        (1 on)
5 ^ 2 = 7        (2 on)
7 ^ 1 = 6        (1 off)
6 ^ 2 = 4        (2 off)

*/