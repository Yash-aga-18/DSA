#include <bits/stdc++.h>
using namespace std;

// leetcode Q->47  Permuation2  

void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans) {

    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    unordered_set<int> used;   // avoid duplicates at this level

    for (int i = index; i < nums.size(); i++) {

        if (used.count(nums[i])) continue;

        used.insert(nums[i]);

        swap(nums[index], nums[i]);   // choose

        backtrack(index + 1, nums, ans);  // explore

        swap(nums[index], nums[i]);   // undo
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<vector<int>> ans;

    backtrack(0, nums, ans);

    return ans;
}


int main() {

    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = permuteUnique(nums);

    for (auto& v : ans) {
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;
}