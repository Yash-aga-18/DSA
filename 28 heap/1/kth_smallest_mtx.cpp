#include <bits/stdc++.h>
using namespace std;

// leetcode Q->378  Find kth smalest elemnt in a mtx


// ------------------------------------------------------------
// METHOD 1: Brute Force (Approach - Max Heap)
// Time  -> O(n^2 log k)
// Space -> O(k)
// ------------------------------------------------------------
int kthSmallest_bruteforce(vector<vector<int>>& matrix, int k) {

    int n = matrix.size();

    // max heap
    priority_queue<int> pq;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            pq.push(matrix[i][j]);

            if(pq.size() > k)   pq.pop(); // remove largest
            
        }
    }

    return pq.top();
}


// ------------------------------------------------------------
// METHOD 2: Optimal (Min Heap - Merge K Sorted Rows)
// Time  -> O(k log n)
// Space -> O(n)
// ------------------------------------------------------------
int kthSmallest_optimal(vector<vector<int>>& matrix, int k) {

    int n = matrix.size();

    // min heap: {value, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // push first element of each row
    for(int i = 0; i < n; i++) {
        pq.push({matrix[i][0], i, 0});
    }

    // process k-1 elements
    while(k > 1) {

        vector<int> top = pq.top();
        pq.pop();

        int r = top[1];
        int c = top[2];

        // push next element from same row
        if(c+1 < n) {
            pq.push({matrix[r][c+1], r, c+1});
        }

        k--;

    }

    return pq.top()[0];
}



int main() {

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {6, 7, 12},
        {11, 14, 14}
    };

    int k = 6;

    cout << "Brute Force Answer: " << kthSmallest_bruteforce(matrix, k) << endl;
    cout << "Optimal Heap Answer: " << kthSmallest_optimal(matrix, k) << endl;

    return 0;
}