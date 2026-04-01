#include <bits/stdc++.h>
using namespace std;

//  leetcode Q->1493 Longest Subarray of 1's After Deleting One Element

// You must delete exactly one element from the binary array.
// Return the length of the longest subarray consisting only of 1s after the deletion.
// If the array contains no 1s, return 0.

// Example:
// nums = [1,1,0,1]       → delete index 2 → longest = [1,1,1] → output = 3
// nums = [0,1,1,1,0,1,1,0,1] → delete index 4 → output = 5
// nums = [1,1,1]        → delete one element → output = 2


void max_ones(vector<int>& arr) {

    int n = arr.size();
    int left = 0;
    int zeros = 0;

    int maxLen = 0;
    int bestIndex = -1;

    int zeroPos = -1; // stores current zero's index in window

    for(int right = 0; right < n; right++) {

        // Expand window
        if(arr[right] == 0) {
            zeros++;
            zeroPos = right;  // keep record of the latest zero inside window
        }

        // Shrink window if we have more than 1 zero
        while(zeros > 1) {

            if(arr[left] == 0)      zeros--;

            left++;
        }

        // Calculate window size
        int currentLen = right - left + 1;

        // Update best window and best zero index
        if(currentLen > maxLen) {
            maxLen = currentLen;
            bestIndex = zeroPos;
        }


    }

    cout << "Delete index: " << bestIndex << endl;
    cout << "Max consecutive ones after deletion: " << maxLen-1 << endl;
}



int main()
{
    
    vector<int>arr = {0,1,1,1,0,1,1,0,1};

    max_ones(arr);


 return 0;

}