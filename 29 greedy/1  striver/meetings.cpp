#include <bits/stdc++.h>
using namespace std;

// GFG --> n meetings in a room
// activity selection problem.


static bool cmp(pair<int,int>& a, pair<int,int>& b) {
    return a.second < b.second; // sort by end time
}

int maxMeetings(vector<int>& start, vector<int>& end) {
        
    int n = start.size();
    if(n == 0)      return 0;

    vector<pair<int,int>> v;

    // combine
    for(int i = 0; i < n; i++) {
        v.push_back({start[i], end[i]});
    }

    // sort by end time
    sort(v.begin(), v.end(), cmp);

    int count = 1; // first meeting always taken
    int lastEnd = v[0].second;

    // greedy selection
    for(int i = 1; i < n; i++) {

        if(v[i].first > lastEnd) {
            count++;
            lastEnd = v[i].second;
        }
    }

    return count;
}



int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << maxMeetings(start, end) << endl;

    return 0;
}