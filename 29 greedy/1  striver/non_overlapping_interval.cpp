#include <bits/stdc++.h>
using namespace std;

// leetcode Q->435      Non-overlapping Intervals

// Hint:--> Just similar to activity selection problem . 
// remove the not possible to select activity as that activity will be overlapping


// comparator to sort by end time
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    
    sort(intervals.begin(), intervals.end(), cmp); // sort by end time


    int count = 0;                  // number of intervals removed
    int lastEnd = intervals[0][1];  // end of last non-overlapping interval

    for(int i = 1; i < intervals.size(); i++) {

        // overlap → remove current interval
        if(intervals[i][0] < lastEnd)   count++;
        
        else                        lastEnd = intervals[i][1]; // update end if no overlap
        
    }

    return count;
}



int main() {

    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}