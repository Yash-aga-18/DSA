#include <bits/stdc++.h>
using namespace std;

//  GFG--> Shortest Job first

int solve(vector<int>& bt) {

    sort(bt.begin(), bt.end()); // O(n log n)

    long long waitSum = 0;
    long long currTime = 0;

    for(int i = 0; i < bt.size(); i++) { // O(n)
        waitSum += currTime;
        currTime += bt[i];
    }

    return waitSum / bt.size();
}

int main() {

    vector<int> bt = {5, 1, 8, 2, 3};

    cout << solve(bt) << endl;

    return 0;
}