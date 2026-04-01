#include <bits/stdc++.h>
using namespace std;

int main()
{
  
// leetcode Q->169
// Q--> The majority element is the element that appears more than ⌊n / 2⌋ times.
//  You may assume that the majority element always exists in the array.


    vector<int>nums = {1,2,3,3,4,4,5,5,5,5,5,5};
    
    
    // int n = nums.size();
    // sort(nums.begin(),nums.end());
    // cout<<n<<endl;

    // for(int i=0; i<n; i++){
    //     int count = 1;
    //     for(int j=i; j<n-1; j++){
    //         if (nums[j]==nums[j+1])     count++;
    //         else                         break;
    //     }
    //     if(count >= (n/2)) {
    //         cout<<nums[i];
    //         break;
    //     }
    // }


//                   OR


    // sort(nums.begin(),nums.end());
    // cout<< nums[n/2];


//                   OR

//  Moore’s Voting Algorithm (also called Boyer–Moore Voting Algorithm).


    int count = 0;
    int candidate = 0;

    for (int num : nums) {

        if (count == 0)         candidate = num; // pick new candidate
        
        if (num == candidate)   count++;  // same as candidate → increment count
        else                    count--;  // different → decrement count
    }

    cout<< candidate;

   return 0;
} 