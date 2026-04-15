#include <bits/stdc++.h>
using namespace std;

// leetcode Q->452      Min arrows to burst all balloons



// comparator to sort by end time
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {

    int n = points.size();
    if(n == 0) return 0;

    // Step 1: sort by end
    sort(points.begin(), points.end(), cmp);


    int arrows = 1; // at least one arrow
    int lastEnd = points[0][1];

    // Step 2: greedy
    for(int i = 1; i < n; i++) {

        // if current balloon starts after lastEnd → need new arrow
        if(points[i][0] > lastEnd) {
            arrows++;
            lastEnd = points[i][1];
        }
    }

    return arrows;
}


int main() {

    // Input
    vector<vector<int>> points = {
        {10,16}, {2,8}, {1,6}, {7,12}
    };

    // Function call
    int result = findMinArrowShots(points);

    // Output
    cout << "Minimum Arrows: " << result << endl;

    return 0;
}