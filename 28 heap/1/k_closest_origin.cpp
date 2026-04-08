#include <bits/stdc++.h>
using namespace std;

// leetcode Q->973   Find K Closest Elements to origin

vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {

    // max heap: {distance, index}
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < arr.size(); i++) {

        int x = arr[i][0];
        int y = arr[i][1];

        int dist = x*x + y*y; // no sqrt needed

        pq.push({dist, i});

        // keep only k closest
        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<vector<int>> ans;

    // extract elements
    while(!pq.empty()) {

        int idx = pq.top().second;
        pq.pop();

        ans.push_back(arr[idx]);
    }

    return ans;
}



int main() {

    vector<vector<int>> arr = {{1,3}, {-2,2}, {5,8}, {0,1}};
    int k = 2;

    vector<vector<int>> result = kClosest(arr, k);

    cout << "K Closest arr:\n";
    for(auto p : result) {
        cout << p[0] << " " << p[1] << endl;
    }

    return 0;
}