#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1679   Max Number of K-Sum Pairs


// 🔹 Method 1: HashMap (O(n))
int maxOperations_hashmap(vector<int>& nums, int target) {

    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {

        int num = nums[i];
        int complement = target - num;

        // if complement exists → form pair
        if (freq[complement] > 0) {
            count++;
            freq[complement]--;
        }

        else    freq[num]++;
        
    }

    return count;
}


// 🔹 Method 2: Two Pointer (O(n log n))
int maxOperations_twopointer(vector<int>& nums, int target) {

    sort(nums.begin(), nums.end());

    int left = 0;
    int right = nums.size() - 1;
    int count = 0;

    while (left < right) {

        int sum = nums[left] + nums[right];

        if (sum == target) {
            count++;
            left++;
            right--;
        }

        else if (sum < target)  left++;   // need bigger sum 
        else                    right--;  // need smaller sum
        
    }

    return count;
}


int main() {

    // 🔥 Test Case
    vector<int> nums = {3,1,3,4,3};
    int k = 6;

    // copy needed because sorting modifies array
    vector<int> nums_copy = nums;

    cout << "Using HashMap: " << maxOperations_hashmap(nums, k) << endl;
    cout << "Using Two Pointer: " << maxOperations_twopointer(nums_copy, k) << endl;

    return 0;
}