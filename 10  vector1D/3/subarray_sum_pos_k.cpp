#include <bits/stdc++.h>
using namespace std;


// Given an array nums of size n and an integer k, find the
// length of the longest sub-array that sums to k. If no such sub-array exists, return 0.

// Input: nums = [10, 5, 2, 7, 1, 9],  k=15
// Output: 4
// Reason:The longest sub-array with sum equal to 15 is [5,2,7,1], which has a length of 4


int main()
{
    vector<int> nums = {1, 2, 1, 1, 1, 3, 2, 1};
    int k = 5;
   
    int n = nums.size();
    int left = 0, right = 0;
    int sum = 0;
    int maxLen = 0;
    int start = -1, end = -1;   // to store subarray boundaries
    

    for (int right = 0; right < nums.size(); right++) {
        sum += nums[right];         // add current element

        while (sum > k) {       // shrink from left
            sum -= nums[left];
            left++;
        }

        if (sum == k) {         // found subarray with sum k

            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
                end = right;
            }

        }
    }


    cout << "Longest Subarray with sum " << k << ": ";

    for (int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout<<endl;

    cout << "Length = " << maxLen << endl;



 return 0;

}