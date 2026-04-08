#include <bits/stdc++.h>
using namespace std;

// GFG problem-->   Minimum cost to connect ropes


int minCost(vector<int>& arr) {

    priority_queue<int, vector<int>, greater<int>> pq;

    // push all elements
    for(int x : arr) {
        pq.push(x);
    }

    int cost = 0;

    while(pq.size() > 1) {

        int a = pq.top(); 
        pq.pop();

        int b = pq.top(); 
        pq.pop();

        int sum = a + b;

        cost += sum;
        pq.push(sum);
    }

    return cost;
}


int main() {

    vector<int> arr = {4, 3, 2, 6};

    cout << "Minimum Cost: " << minCost(arr) << endl;

    return 0;
}