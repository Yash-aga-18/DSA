#include <bits/stdc++.h>
using namespace std;

// leetcode Q->55   Jump Game 1


bool canJump(vector<int>& nums) {

    int maxReach = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(i > maxReach)        return false; // cannot reach this index

        maxReach = max(maxReach, i + nums[i]); // update reach
    }

    return true;
}

int main() {

    vector<int> nums = {2,3,1,1,4};

    cout << (canJump(nums) ? "true" : "false") << endl;

    return 0;
}