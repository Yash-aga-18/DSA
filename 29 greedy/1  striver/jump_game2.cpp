#include <bits/stdc++.h>
using namespace std;

// leetcode Q->45   Jump Game 2


int jump(vector<int>& nums) {
    
    int n = nums.size();
    
    int l = 0;
    int r = 0; // current range [l, r]
    int jumps = 0;

    while(r < n - 1) {

        int farthest = 0;

        // explore all indices in current range
        for(int i = l; i <= r; i++) {
            farthest = max(farthest, i + nums[i]);
        }

        // move to next range (next jump)
        l = r + 1;
        r = farthest;

        jumps++; // one jump completed
    }

    return jumps;
    
}

int main() {

    vector<int> nums = {2,3,1,1,4};

    cout << jump(nums) << endl;

    return 0;
}