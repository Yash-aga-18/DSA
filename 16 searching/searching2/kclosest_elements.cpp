#include <bits/stdc++.h>
using namespace std;

// leetcode Q->658
// you given a sorted array.  You are required to push the K closest elements to target.

// Input: arr = [1,2,3,4,5], k = 2,target = 3
// Output: [2,3]

int main()
{
    int arr[] = {1,2,3,5,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    int target = 7;
    vector<int>v;

    
    int left = 0, right = n - k;

    while (left < right) {

        int mid = left + (right-left) / 2;

        int distLeft  = target - arr[mid];      // distance from target to left bound
        int distRight = arr[mid + k] - target;  // distance from target to right bound

        
        if (distLeft > distRight)   left = mid + 1;
        else                        right = mid;
        
    }

    // Now 'left' is the start of window
    for (int i = left; i < left + k; i++)   v.push_back(arr[i]);
    

    // Print the result
    for (int ele : v)                   cout << ele << " ";


 return 0;

}


// We check:
// ➡️ Should we keep this window (or move left)?
// ➡️ Or move right to a better window (closer to x)?


// x - arr[mid] > arr[mid + k] - x
// That means:
// The left side (arr[mid]) is farther from x
// The right side (arr[mid+k]) is closer to x
// ➡️ So the window should slide right → low = mid + 1.