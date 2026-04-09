#include <bits/stdc++.h>
using namespace std;

vector<int> heapSort(vector<int>& nums) {
    
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    // step 1: push all elements
    for(int i = 0; i < nums.size(); i++) {
        pq.push(nums[i]);
    }

    // step 2: extract in sorted order
    vector<int> sorted;

    while(pq.size() > 0) {
        sorted.push_back(pq.top());
        pq.pop();
    }

    return sorted;
}

int main() {

    vector<int> nums = {5, 3, 8, 1, 6};

    vector<int> ans = heapSort(nums);

    cout << "Sorted array: ";
    for(int x : ans) {
        cout << x << " ";
    }

    return 0;
}