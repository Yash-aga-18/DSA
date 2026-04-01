#include <bits/stdc++.h>
using namespace std;

//  leetcode Q->209  Minimum Size Subarray Sum

//  Find minimal length of a subarray whose sum is greater than or equal to target.
//  If there is no such subarray, return 0 instead.

// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Ekplanation: The subarray [4,3] has the minimal length under the problem constraint.


int subarraySum1(vector<int>& arr, int target) {
    
    int n = arr.size();
    int length = 0;

    for(int k=1; k<=n; k++){
        int currSum = 0;

        for(int i=0; i<k; i++)  currSum += arr[i];
        if(currSum >= target)   return k;
    
        for(int high=k; high<n; high++){
            int low = high-k+1;

            currSum += arr[high] - arr[low-1];

            if(currSum >= target)   return k;
        }
        
    }

    return length;

}
// Time Complexity: O(n^2)   Space Complexity: O(1)


int subarraySum2( vector<int>& arr, int target) {

    int n = arr.size();
    int left = 0;
    int sum = 0;
    int ans = INT_MAX;

    for(int right = 0; right < n; right++) {

        sum += arr[right];  // expand window

        while(sum >= target) {   // valid window found

            int len = right-left+1;

            ans = min(ans, len);
            sum -= arr[left];   // shrink from left
            left++;
        }

    }

    if(ans == INT_MAX)   return 0;
    else                 return ans;

}
// Time Complexity: O(n)   Space Complexity: O(1)



int main()
{
    
    // vector<int>arr = {7,1,2,5,8,4,9,3,6};
    vector<int>arr = {2,3,1,2,4,3};
    int target = 7;

    // cout<<subarraySum1(arr,target);
    cout<<subarraySum2(arr,target);


 return 0;

}