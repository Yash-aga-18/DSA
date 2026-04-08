#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1636 
// Sort Array by Increasing Frequency; if tie → value should in decreasing order


//  Using  hashmap + map
vector<int> frequencySort1(vector<int>& nums) {

    unordered_map<int,int> mp;
    for(int x : nums)       mp[x]++;
    

    // Step 2: group by frequency
    map<int, vector<int>> mp2;
    for(auto it : mp) {

        int ele  = it.first;
        int freq = it.second;
        
        mp2[freq].push_back(ele);
    }
    
    
    vector<int> ans;
    for(auto it : mp2) {

        int freq  = it.first;

        vector<int> temp = it.second;

        // sort values in decreasing order
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        // Step 4: push elements freq times
        for(int val : temp) {
            for(int i = 0; i < freq; i++) {
                ans.push_back(val);
            }
        }
    }

    return ans;
}


// Optimal approach  using only 1 hashmap
vector<int> frequencySort2(vector<int>& nums) {

    unordered_map<int, int> mp;

    // Step 1: frequency count
    for(int x : nums)       mp[x]++;


    // Step 2: sort nums directly
    sort(nums.begin(), nums.end(), [&](int a, int b){

        if(mp[a] == mp[b])      return a > b;  // value descending
    
        return mp[a] < mp[b];                   // freq ascending
    });

    return nums;
}


int main() {

    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};

    vector<int> result1 = frequencySort1(nums);
    vector<int> result2 = frequencySort2(nums);

    cout << "Sorted array: ";
    for(int x : result1) {
        cout << x << " ";
    }

    return 0;
}