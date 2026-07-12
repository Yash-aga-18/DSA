#include <bits/stdc++.h>
using namespace std;
// leetcode Q->31

// // next permutation of array is greater than prev one
// eg arr1[]={1,2,3,4}
// you are given 2134 then the next perm is 2314


void next_perm(vector<int>&nums ){

    int pivot = -1;

    for(int i = nums.size()-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            pivot=i;
            break;
        }
    }

    if(pivot == -1){    
        reverse(nums.begin(),nums.end());    
        return ;
    }
    
    reverse(nums.begin()+(pivot+1),nums.end());

    for(int  i = (pivot+1); i<nums.size(); i++){
        
        if(nums[i]>nums[pivot]){
            swap(nums[pivot],nums[i]);  
            break;
        }   
    }

}



int main()
{
    vector<int>nums(5);
    cout<<"enter the perm. of an array from 1 to 5"<<endl;

    for(int i=0;i<nums.size(); i++){                    // taking input of perm from user
        cin>>nums[i];
    }

    for(int i=0;i<nums.size(); i++){                // print a vector
     cout<<nums[i]<<" ";
    }
    cout<<endl;


    next_perm(nums);


    for(int i=0;i<nums.size(); i++){                // print next perm
        cout<<nums[i]<<" ";
    }



 return 0;

}