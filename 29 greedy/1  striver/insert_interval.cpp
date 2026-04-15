#include <bits/stdc++.h>
using namespace std;

// leetcode Q->57  Insert Interval


vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    int n = intervals.size();
    vector<vector<int>> ans;

    int i = 0;
    
    // 1. add all intervals before newInterval
    while(i < n && intervals[i][1] < newInterval[0]) {
        ans.push_back(intervals[i]);
        i++;
    }

    
    
    // 2. merge overlapping intervals
    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);


    
    // 3. add remaining intervals
    while(i < n) {
        ans.push_back(intervals[i]);
        i++;
    }
    
    return ans;

}



int main() {

    vector<vector<int>> intervals = {{1,3}, {6,9}};
    vector<int> newInterval = {2,5};

    vector<vector<int>> result = insert(intervals, newInterval);

    for(auto &v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}