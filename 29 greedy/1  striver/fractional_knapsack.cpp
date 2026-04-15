#include <bits/stdc++.h>
using namespace std;

// GFG---> Fractional knapsack


// Custom comparator
static bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
    
    // a.first  = value
    // a.second = weight
    
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;

    return r1 > r2; // // Return true if the ratio of item a is greater than item b
}


double fractionalKnapsack(vector<long long>& val, vector<long long>& wt, long long capacity) {

    int n = val.size();

    // Step 1: Store (value, weight) together
    vector<pair<long long, long long>> items;

    for(int i = 0; i < n; i++) {
        items.push_back({val[i], wt[i]});
    }

    // Step 2: Sort by value/weight ratio
    sort(items.begin(), items.end(), cmp);

    double totalValue = 0.0;

    // Step 3: Traverse and pick items
    for(int i = 0; i < n; i++) {

        long long value  = items[i].first;
        long long weight = items[i].second;

        // If full item can be taken
        if(capacity >= weight) {

            totalValue += value;
            capacity -= weight;
        }
        else {
            // Take fraction

            double fraction = (double)capacity / weight;
            totalValue += value * fraction;

            break; // knapsack full
        }
    }

    return totalValue;
}



int main() {

    vector<long long> val = {100, 60, 120};
    vector<long long> wt  = {20, 10, 30};

    long long capacity = 50;

    double ans = fractionalKnapsack(val, wt, capacity);
    cout << "ans = "<<ans << endl;

    return 0;
}

/*
==================== FRACTIONAL KNAPSACK ====================

Problem:
Given N items, each with:
- value[i]
- weight[i]

And a knapsack with capacity W.
You can take FRACTIONS of items.
Goal: Maximize total value.

-------------------------------------------------------------
Example:
Input:
N = 3
values  = {60, 100, 120}
weights = {10, 20, 30}
W = 50

Output: 240

-------------------------------------------------------------
Key Idea:
Greedy → pick item with highest (value/weight) first

Time Complexity: O(N log N)
=============================================================
*/
