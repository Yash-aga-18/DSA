#include <bits/stdc++.h>
using namespace std;

// leetcode Q->252 / 920 Lintcode       Meeting rooms 

#include <bits/stdc++.h>
using namespace std;

// Function to check if all meetings can be attended
bool canAttendMeetings(vector<vector<int>>& intervals) {

    // Step 1: sort by start time
    sort(intervals.begin(), intervals.end());

    // Step 2: check overlap
    for(int i = 1; i < intervals.size(); i++) {

        int prevEnd = intervals[i-1][1];
        int currStart = intervals[i][0];

        if(currStart < prevEnd) {
            return false; // overlap
        }
    }

    return true;
}



int main() {

    // Example 1
    vector<vector<int>> intervals = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    if(canAttendMeetings(intervals)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}