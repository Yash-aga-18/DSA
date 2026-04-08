#include <bits/stdc++.h>
using namespace std;

// leetcode Q->347  give top k freq elemnts in any order
// Optimized: O(n log k)


typedef pair<int ,int> pi;  // just to make the code clean

vector<int> topKFrequent(vector<int>& arr, int k) {
    
    unordered_map<int, int>mp;   //value,freq
    for(int ele: arr)       mp[ele]++;
    

    // we want the min-heap is to store (freq,value) as min heap decide on the first value 
    priority_queue<pi, vector<pi>, greater<pi> >pq;

    for(auto ele: mp){
        // int val  = ele.first;
        // int freq = ele.second;
    
        // pair<int, int>p = {freq, val};
        // pq.push(p);


        pq.push( {ele.second, ele.first} );
        if(pq.size() >k)    pq.pop();
    
    }


    vector<int> ans;

    while(!pq.empty()){

        int ele = pq.top().second;

        ans.push_back(ele);
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