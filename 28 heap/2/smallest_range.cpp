#include <bits/stdc++.h>
using namespace std;

// leetcode Q->632  Smallest Range Covering Elements from K Lists

/*
You are given k sorted lists of numbers.
You need to find a small range [a, b] such that:    

👉 Find the smallest possible range
👉 It contains at least one number from every list
👉 if there are 2 same ranges  pick one which have starting value is smaller   
    Range [a, b] is better than [c, d]     if a<=c
*/


vector<int> smallestRange(vector<vector<int>>& nums) {
    
    int k = nums.size();

    // min heap -> {value, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int maxi = INT_MIN;

    // push first element of each list
    for(int i = 0; i < k; i++) {

        pq.push({nums[i][0], i, 0});
        
        if(nums[i][0] > maxi)       maxi = nums[i][0];
        
    }

    int start = 0;
    int end = INT_MAX;

    while(true) {

        vector<int> temp = pq.top();
        pq.pop();

        int mini = temp[0];
        int row  = temp[1];
        int col  = temp[2];

        // update answer
        if( (maxi - mini)  <  (end - start) ) {

            start = mini;
            end   = maxi;
        }

        // move in same list and check if it is possible to move
        if(col+1 < nums[row].size()) {

            int nextVal = nums[row][col+1];

            pq.push({nextVal, row, col+1});
            if(nextVal > maxi)  maxi = nextVal;
            
        }
        else    break;      // if any one of the list finished
        
    }

    return {start, end};
}

int main() {

    vector<vector<int>> nums = {
        {4,10,15,24,26},
        {0,9,12,20},
        {5,18,22,30}
    };

    vector<int> result = smallestRange(nums);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}