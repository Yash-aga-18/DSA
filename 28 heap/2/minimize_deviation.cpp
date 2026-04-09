#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1675  Minimize the deviation in array
// we can divide   the element by 2 if even
// we can multiply the element by 2 if odd

// we can perfrom above seps any no. of times we need



int minimumDeviation(vector<int>& nums) {

    priority_queue<int> pq; // max heap
    int mini = INT_MAX;

    // Step 1: make all numbers even (so we can only decrease later)
    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] % 2 == 1)    nums[i] = nums[i] * 2; // make odd → even
        

        pq.push(nums[i]);
        mini = min(mini, nums[i]); // track minimum
    }

    int ans = INT_MAX;

    // Step 2: reduce the maximum element
    while(true) {

        int maxi = pq.top(); // current max
        pq.pop();

        ans = min(ans, maxi - mini); // update deviation

        // if max is even → we can reduce it
        if(maxi % 2 == 0) {

            int newVal = maxi / 2;

            mini = min(mini, newVal); // update minimum
            pq.push(newVal);

        }

        else   break; // cannot reduce further
        
    }

    return ans;
}

int main() {

    vector<int> nums = {1,2,3,4};

    cout << minimumDeviation(nums) << endl; // 1

    return 0;
}