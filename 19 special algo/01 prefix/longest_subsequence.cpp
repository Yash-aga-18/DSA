#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2389. Longest Subsequence With Limited Sum

// Input: nums = [4,5,2,1], queries = [3,10,21]
// Output: [2,3,4]

// - The subsequence [2,1] has a sum less than or equal to 3
// - The subsequence [4,5,1] has a sum less than or equal to 10
// - The subsequence [4,5,2,1] has a sum less than or equal to 21
// We have to put length of the longest  in output 


void subsequence2(vector<int>& queries, vector<int>& nums){         // most efficient
    
    sort(nums.begin(), nums.end());         // sort nums
    int m = queries.size();
    int n = nums.size();
    
    for(int i = 1; i<n; i++)    nums[i] += nums[i-1];
    

    for(int ele:nums)    cout<<ele<<" ";         // print  prefix_sum
    cout<<endl;
    
    
    vector<int> answer(m);
    for(int i=0; i<m; i++){

        int target = queries[i];
        
        int low = 0;
        int high = n-1;
        
        while(low<=high){
            
            int mid = low+(high-low)/2;

            if( nums[mid] > target )     high = mid-1;
            else                         low  = mid+1;

        }

        answer[i] = low;
    }

    for(int ele:answer)    cout<<ele<<" ";         // print  answer
    cout<<endl;

}



void subsequence1(vector<int>& queries, vector<int>& nums){
    
    sort(nums.begin(), nums.end());         // sort nums
    int m = queries.size();
    int n = nums.size();
    vector<int> pre_sum(n);
    
    pre_sum[0] = nums[0];                   // make prefix sum of nums arr
    for(int i = 1; i<n; i++){
        pre_sum[i] = pre_sum[i-1]+nums[i];
    }
    
    for(int ele:pre_sum)    cout<<ele<<" ";         // print  prefix_sum
    cout<<endl;
    

    vector<int> answer(m);
     
    
    for(int i=0; i<m; i++){
        int idx = 0;
        int target = queries[i];
        

        for(int j=0; j<n; j++){
            if(pre_sum[j]<=target)    idx = j+1;
            else                      break;

        }

        answer[i] = idx; 

    }

    for(int ele:answer)    cout<<ele<<" ";         // print  answer
    cout<<endl;


}



int main()
{
    vector<int> queries = {3,10,21} ;
    vector<int> nums    = {4,5,2,1};

//    subsequence1(queries,nums);     // simple

    subsequence2(queries,nums);     // most efficient


 return 0;

}