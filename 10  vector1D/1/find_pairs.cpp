#include <bits/stdc++.h>
using namespace std;

/*
GFG-->Find all pairs with a given sum
Given two arrays arr1[] and arr2[] and an integer target,
find all pairs (x, y) such that:

    x belongs to arr1
    y belongs to arr2
    x + y == target

Return all such pairs sorted in ascending order of the first element.
If an element appears multiple times in either array, include all valid pairs.
*/


vector<pair<int, int>> allPairs(int target, vector<int> &arr1, vector<int> &arr2) {

    unordered_map<int, int> mp;

    // Store frequency of elements in arr2
    for (int x : arr2)      mp[x]++;
    vector<pair<int, int>> ans;

    // Find all valid pairs
    for (int x : arr1) {
        int diff = target - x;

        if (mp.find(diff) != mp.end()) {
            for (int i = 0; i < mp[diff]; i++)  ans.push_back({x, diff});
        }
    }

    // Sort pairs by first element, then second element
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    int target = 9;

    vector<int> arr1 = {1, 2, 4, 5, 7, 4};
    vector<int> arr2 = {5, 6, 3, 4, 8, 4};

    vector<pair<int, int>> ans = allPairs(target, arr1, arr2);

    cout << "Pairs:\n";

    for (auto p : ans) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}