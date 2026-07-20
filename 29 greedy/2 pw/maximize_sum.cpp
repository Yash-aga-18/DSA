#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1005     Maximize Sum Of Array After K Negations


// 🔴 Approach 1: Your Min Heap Method
int solveUsingMinHeap(vector<int> arr, int k) {
        
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)     sum += arr[i];


    // priority_queue<int, vector<int>, greater<int>> pq;       // takes O(n logn) for each insertion
    // for(int i = 0; i < arr.size(); i++) {
    //     pq.push(arr[i]);
    // }

    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());  // takes O(n) total


    while(k > 0) {
        int ele = pq.top();
        if(ele == 0)    break;   // flipping 0 does nothing
        

        pq.pop();
        sum -= ele;     // remove old value
        

        pq.push(-ele);  // insert flipped value
        sum += (-ele);  // add new value


        k--;
    }

    return sum;
}



// 🟢 Approach 2: Optimized Greedy Method
int solveOptimized(vector<int> arr, int k) {

    sort(arr.begin(), arr.end());

    // Step 1: flip negatives
    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] < 0 && k > 0) {
            arr[i] = -arr[i];
            k--;
        }
    }

    // Step 2: find sum and minimum
    int sum = 0;
    int mini = INT_MAX;

    for(int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        mini = min(mini, arr[i]);
    }

    // Step 3: if k is odd → flip smallest
    if(k % 2 == 1) {
        sum -= 2 * mini;
    }

    return sum;
}


int main() {

    // 🔹 Test Case
    vector<int> arr = {-2, 5, 0, 2, -3};
    int k = 3;

    // Call both functions
    int ans1 = solveUsingMinHeap(arr, k);
    int ans2 = solveOptimized(arr, k);

    cout << "Min Heap Answer: " << ans1 << endl;
    cout << "Optimized Answer: " << ans2 << endl;

    return 0;
}