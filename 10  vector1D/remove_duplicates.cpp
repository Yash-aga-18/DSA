#include <bits/stdc++.h>
using namespace std;
// leetcode Q->26 remove duplicates from array doing in place element

// Input:       nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5;   nums = [0,1,2,3,4,_,_,_,_,_]


int main()
{
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    int j = 0;

    for(int i=1; i<nums.size(); i++){
    
        if(nums[i]!=nums[j])    {
            j++;
            nums[j]= nums[i];
    
        }

    }


    cout<< j+1;


 return 0;

}