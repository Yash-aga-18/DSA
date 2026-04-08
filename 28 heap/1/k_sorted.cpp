#include <bits/stdc++.h>
using namespace std;

// you are given an array where every element is 
// at most k positions away from its correct sorted position.
// at any index from i - k to i + k.


void nearlySorted(vector<int>& arr, int k) {
    
    int n = arr.size();
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int idx = 0;
    
    for(int i = 0; i < n; i++){
        
        pq.push(arr[i]);
        
        // maintain size k+1  beacuse the curr elemnt can be at most at (k+1) place 
        if(pq.size() > k){
            arr[idx++] = pq.top();
            pq.pop();
        }
        
    }
    
    // remaining elements
    while(!pq.empty()){
        arr[idx++] = pq.top();
        pq.pop();
    }
    
}

int main() {

    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    nearlySorted(arr, k);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}