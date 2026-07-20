#include <bits/stdc++.h>
using namespace std;

// leetcode Q->45   Jump Game 2


int jump(vector<int>& arr) {
    
    int n = arr.size();

    if(n == 1)  return 0;

    int l = 0;
    int r = 0;
    int jumps = 0;

    while(r < n - 1){

        int farthest = r;

        for(int i = l; i <= r; i++){
            farthest = max(farthest, i + arr[i]);
        }

        // Can't move any further
        if(farthest == r)   return -1;

        l = r + 1;
        r = farthest;
        jumps++;
    }

    return jumps;
    
}

int main() {

    vector<int> nums = {2,3,1,1,4};

    cout << jump(nums) << endl;

    return 0;
}