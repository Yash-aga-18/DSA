#include <bits/stdc++.h>
using namespace std;

// leetcode Q->560      Subarray Sum Equals K


// method1 and method 2 can be used only for +ve arrays.    But this ques is also have -ve integers
 
// method1      using binary serach and prefix sum array 
// method2      using set and prefix sum array 

int subarraySum_binary(vector<int>& nums, int target) {

    int n = nums.size();

    vector<int> pre(n);
    pre[0] = nums[0];

    for(int i = 1; i < n; i++)  pre[i] = pre[i-1] + nums[i];

    int count = 0;
    for(int i = 0; i < n; i++) {

        // Case 1: subarray from 0 → i
        if(pre[i] == target)    count++;

        int req = pre[i] - target;

        // Binary search in [0, i-1]
        int low = 0, high = i-1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(pre[mid] == req) {
                count++;
                break;
            }
            
            else if(pre[mid] < req)     low = mid + 1;
            else                        high = mid - 1;
            
        }
    }

    return count;
}

int subarraySum_set(vector<int>& nums, int k) {

    int n = nums.size();

    vector<int> pre(n, 0);
    pre[0] = nums[0];

    for(int i = 1; i < n; i++)      pre[i] = nums[i] + pre[i - 1];
    

    unordered_set<int> s;
    int count = 0;

    for(int i = 0; i < n; i++){

        if(pre[i] == k)     count++;

        int rem = pre[i] - k;
        if(s.find(rem) != s.end())  count++;

        s.insert(pre[i]);
    }

    return count;
}


int subarraySum(vector<int>& nums, int k) {

    int n = nums.size();

    // Step 1: prefix sum array
    vector<int> pre(n);
    pre[0] = nums[0];

    for (int i = 1; i < n; i++)     pre[i] = pre[i - 1] + nums[i];
    
    // Step 2: hashmap
    unordered_map<int, int> mp;
    int count = 0;

    for (int i = 0; i < n; i++) {

        // case 1: from 0 to i
        if (pre[i] == k)    count++;

        // case 2: previous prefix exists
        int rem = pre[i] - k;
        if (mp.find(rem) != mp.end())   count += mp[rem];
        

        mp[pre[i]]++;
    }

    return count;

}




int main() {

    int n = 6;
    int target = 5;
    
    vector<int> nums= {3, 4, 7, -2, 2, 1};

    cout<<"target is "<<target<<endl;
    for (int i = 0; i < n; i++) {
        cout<< nums[i]<< " ";
    }
    cout<<endl;

    cout << subarraySum(nums, target) << endl;

    return 0;
}