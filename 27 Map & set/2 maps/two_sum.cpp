#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1        Two Sum using Hashmap


// 🔹 Two Sum function
vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map< int , int> mp;

    for(int i=0; i<nums.size(); i++){
        int diff = target - nums[i];

        if(mp.find(diff) != mp.end()) {     // we found the pair 
            return { mp[diff], i  };
        }
        else  mp[nums[i]] = i;              // insert for future check

    }

    return { };                         // unable to find any pair

    
}


int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    for(int ele : nums)     cout<<ele<<" ";
    cout<<endl;
    cout<<"target is : "<<target;
    cout<<endl;

    

    vector<int> ans = twoSum(nums, target);

    if(ans.size() == 2) {
        cout << "Indices: " << ans[0] << " " << ans[1] << endl;
    }
    else {
        cout << "No solution found" << endl;
    }

    return 0;
}