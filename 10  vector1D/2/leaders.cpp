#include <bits/stdc++.h>
using namespace std;

/*
Question: Leaders in an Array (GFG)

An element is called a leader if it is greater than or equal to all the elements to its right.
The rightmost element is always a leader.

Return all the leaders in the same order as they appear in the array.
Example: 
Input:{16, 17, 4, 3, 5, 2}
Output: 17 5 2
*/


vector<int> leaders(vector<int>& arr) {

    int n = arr.size();
    vector<int> ans;

    // Last element is always a leader
    ans.push_back(arr[n - 1]);
    int maxRight = arr[n - 1];

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {

        if (arr[i] >= maxRight) {
            maxRight = arr[i];
            ans.push_back(arr[i]);
        }
    }

    // Reverse to restore original order
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {

    vector<int> arr = {16, 17, 4, 3, 5, 2};

    vector<int> ans = leaders(arr);

    cout << "Leaders are:\n";

    for (int x : ans)
        cout << x << " ";

    cout << endl;

    return 0;
}