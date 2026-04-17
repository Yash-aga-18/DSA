#include <bits/stdc++.h>
using namespace std;

// leetcode Q->3761  Minimum Absolute Distance Between Mirror Pairs


// reverse a number
int rever(int x) {
    int rev = 0;

    while (x > 0) {
        int d = x % 10;        // extract last digit
        rev = rev * 10 + d;    // build reversed number
        x = x / 10;            // remove last digit
    }

    return rev;
}


int minMirrorPairDistance(vector<int>& arr) {

    int n = arr.size();

    unordered_map<int, int> mp;   // stores number → index

    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {

        int ele = arr[i];
        int rev = rever(ele);   // reverse of current number

        // check if same number seen before (as reverse earlier)
        if (mp.find(ele) != mp.end()) {
            ans = min(ans, i - mp[ele]);   // update minimum distance
        }

        // store reverse as key for future matches
        mp[rev] = i;
    }

    if (ans == INT_MAX) return -1;

    return ans;
}


int main() {

    vector<int> arr = {123, 321, 456, 654, 111};

    int result = minMirrorPairDistance(arr);

    cout << result << "\n";

    return 0;
}