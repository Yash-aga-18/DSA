#include <bits/stdc++.h>
using namespace std;


// leetcode Q->658   Find K Closest Elements using Max Heap

vector<int> findClosestElements(vector<int>& arr, int k, int target) {

    // max heap: {distance, value}
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < arr.size(); i++) {

        int dist = abs(arr[i] - target);

        pq.push({dist, arr[i]});

        // keep only k elements
        if(pq.size() > k) {
            pq.pop();
        }
    }

    vector<int> ans;

    // extract elements
    while(!pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    // final answer should be sorted
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int target = 3;

    vector<int> result = findClosestElements(arr, k, target);

    cout << "Closest elements: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}