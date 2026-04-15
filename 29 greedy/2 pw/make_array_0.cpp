#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2357     Make Array Zero by Subtracting Equal Amounts
// Hint --> as we required only no of distict elemnts to get the answers

int minimumOperations(vector<int>& arr) {

    unordered_set<int> st;

    // store only non-zero distinct elements
    for(int ele : arr) {
        
        if(ele > 0)     st.insert(ele);
    }

    return st.size();
}

int main() {

    // Input
    vector<int> arr = {1, 5, 0, 3, 5};

    // Function call
    int result = minimumOperations(arr);

    // Output
    cout << "Minimum Operations: " << result << endl;

    return 0;
}