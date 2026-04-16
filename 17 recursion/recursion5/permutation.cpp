#include <bits/stdc++.h>
using namespace std;

// leetcode Q->46  Permuation

void backtrack(int index, vector<int>& nums, vector<vector<int>>& ans) {

    if (index == nums.size()) {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++) {

        swap(nums[index], nums[i]);   // choose

        backtrack(index + 1, nums, ans);  // explore

        swap(nums[index], nums[i]);   // undo
    }
}


vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> ans;

    backtrack(0, nums, ans);

    return ans;
}


int main() {

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (auto& v : ans) {
        for (auto x : v) cout << x << " ";
        cout << "\n";
    }

    return 0;
}