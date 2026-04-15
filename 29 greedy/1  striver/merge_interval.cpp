#include <bits/stdc++.h>
using namespace std;

// leetcode Q->56  Merge Interval


vector<vector<int>> merge(vector<vector<int>>& intervals) {

    int n = intervals.size();;

    // sort by start time
    sort(intervals.begin(), intervals.end());


    vector<vector<int>> ans;

    ans.push_back(intervals[0]);
    for(int i = 1; i < n; i++) {

        // if overlap → merge
        if(intervals[i][0] <= ans.back()[1]) {

            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        
        else    ans.push_back(intervals[i]);
        
    }

    return ans;
}


int main() {

    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<vector<int>> result = merge(intervals);

    for(auto &v : result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}