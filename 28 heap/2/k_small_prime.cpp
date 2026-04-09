#include <bits/stdc++.h>
using namespace std;

// leetcode Q->786  K-th Smallest Prime Fraction

typedef pair<double, pair<int,int>> pi;
vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

    int n = arr.size();

    // min heap -> stores {fraction value, i, j}
    priority_queue< pi, vector<pi>, greater<pi>> pq;


    // Step 1: push fractions with denominator = last element
    // push all fractions with denominator = last element
    for(int i = 0; i < n - 1; i++) {

        double val = (double)arr[i] / arr[n - 1];
        pq.push({val, {i, n-1} } );
    }

    // remove k-1 smallest
    for(int count = 1; count < k; count++) {

        auto top = pq.top();
        pq.pop();

        int i = top.second.first;
        int j = top.second.second;

        // move denominator left
        if(j - 1 > i) {
            double val = (double)arr[i] / arr[j - 1];
            pq.push( {val, {i, j-1}} );
        }

    }

    // top is kth smallest
    auto ans = pq.top();

    int i = ans.second.first;
    int j = ans.second.second;

    return {arr[i], arr[j]};

}

int main() {

    vector<int> arr = {1,2,3,5};
    int k = 3;

    vector<int> res = kthSmallestPrimeFraction(arr, k);

    cout << res[0] << "/" << res[1] << endl;

    return 0;
}