#include <bits/stdc++.h>
using namespace std;

// leetcode Q->441. Arranging Coins
// return the max rows can be filled completely using the coins fitted in staircase pattern
// Input: n = 8
// Output: 3
// Explanation: Because the 4th row is incomplete, we return 3.


int main() {

    long long n = 80;             
    
    long long low = 1;
    long long high = n;
    long long mid = -1;
    long long ans = 0;

    while(low<=high){
        mid  = low + (high-low)/2;

        // Total coins needed for 'mid' rows
        long long coins = mid * (mid + 1) / 2;

        if (coins == n){
            cout << mid;
            return 0;
        }

        if (coins < n)  low = mid + 1;   // can build more rows
        
        else            high = mid - 1;  // too many coins used
    }
    

    cout << high;    // high  will be the last complete row possible
  
  
  
 return 0;

}