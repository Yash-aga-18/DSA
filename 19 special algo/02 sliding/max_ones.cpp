#include <bits/stdc++.h>
using namespace std;

//  leetcode Q->1004. Max Consecutive Ones III

//  Given a binary array nums and an integer k, return the maximum number of consecutive 1's 
//  in the array if you can flip at most k 0's.

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation:  [1,1,1,0,0,1,1,1,1,1,1]

int max_ones(vector<int>& arr, int k) {

    int n = arr.size();
    int left = 0;           // start of window
    int zeros = 0;          // count how many zeros are inside the window
    int maxLen = 0;         // result: maximum window length

    for(int right = 0; right < n; right++) {

        // Include current element in window
        if(arr[right] == 0)     zeros++;

        // If window has more than k zeros, shrink it from the left
        while(zeros > k) {

            if(arr[left] == 0)      zeros--;

            left++;              // move the window start forward
        }

        // Calculate current valid window size
        int windowSize = right - left + 1;


        // Update max length if this window is larger
        maxLen = max(maxLen,windowSize);
    }

    return maxLen;
}



int main()
{
    
    vector<int>arr = {1,0,1,0,1,0,1,1,0,1,0};
    int k = 1;

    cout<<max_ones(arr,k);


 return 0;

}