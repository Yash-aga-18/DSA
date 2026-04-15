#include <bits/stdc++.h>
using namespace std;

// leetcode Q->253 / 991 Lintcode       Meeting rooms 2
// similar to GFG min platforms


int minMeetingRooms(vector<vector<int>>& intervals) {

    int n = intervals.size();

    // Step 1: break into start & end arrays
    vector<int> start(n), end(n);

    for(int i = 0; i < n; i++) {
        start[i] = intervals[i][0];
        end[i]   = intervals[i][1];
    }

    // Step 2: sort both arrays
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    int i = 0, j = 0;
    int rooms = 0;
    int ans = 0;

    
    // Step 3: same as platform logic
    while(i < n && j < n) {

        if(start[i] < end[j]) {
            rooms++;   // new meeting → need room
            i++;
        }
        else {
            rooms--;   // meeting ended → free room
            j++;
        }

        ans = max(ans, rooms);
    }

    return ans;
}

int main() {

    // LeetCode style input
    vector<vector<int>> intervals = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int result = minMeetingRooms(intervals);

    cout << "Minimum Meeting Rooms: " << result << endl;

    return 0;
}