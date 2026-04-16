#include <bits/stdc++.h>
using namespace std;

// leetcode Q->3075     Maximize Happiness of Selected Children


// ----------- SORTING SOLUTION -----------
long long solveUsingSorting(vector<int> arr, int k) {

    sort(arr.begin(), arr.end());

    long long ans = 0;
    int n = arr.size();

    for (int i = 0; i < k; i++) {

        long long temp = arr[n - 1 - i] - i;

        if (temp <= 0) break;

        ans += temp;
    }

    return ans;
}


// ----------- MAX HEAP SOLUTION -----------
long long solveUsingMaxHeap(vector<int> arr, int k) {

    priority_queue<int> pq(arr.begin(), arr.end());

    long long ans = 0;
    for (int i=0; i<k; i++){

        long long temp = pq.top() - i;
        if (temp < 0)       return ans;

        ans += temp;
        pq.pop();

    }
    return ans;
}


// ----------- MAIN FUNCTION -----------
int main() {

    vector<int> arr = {1, 2, 3};
    int k = 2;

    cout << "Max Heap Solution: " << solveUsingMaxHeap(arr, k) << endl;
    cout << "Sorting Solution: " << solveUsingSorting(arr, k) << endl;

    return 0;
}