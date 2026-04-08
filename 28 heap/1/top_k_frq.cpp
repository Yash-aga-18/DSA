#include <bits/stdc++.h>
using namespace std;

// GFG Style: sorted by freq desc, if same → larger value first

vector<int> topKFrequent(vector<int>& arr, int k) {

    unordered_map<int,int> mp;

    // count frequency
    for(int x : arr)    mp[x]++;
    

    // max heap (freq, value)
    priority_queue<pair<int,int>> pq;

    for(auto it : mp) {
        pq.push( {it.second, it.first} );
    }

    vector<int> ans;

//  Heap priority:
// Higher frequency first 
// If same freq → larger value first 

    while(k--) {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    return ans;
}


int main() {

    vector<int> arr = {7, 10, 11, 5, 2, 5, 5, 7, 11, 8, 9};
    int k = 4;

    vector<int> res = topKFrequent(arr, k);

    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}