#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1944  Number of visible persons in a queue


vector<int> canSeePersonsCount(vector<int>& arr) {

    int n = arr.size();
    vector<int> ans(n, 0);

    stack<int> st;
    st.push(arr[n - 1]);     // last person sees nobody

    for (int i = n - 2; i >= 0; i--) {

        int ele = arr[i];
        int count = 0;

        // remove shorter or equal people (they are visible)
        while (!st.empty() && st.top() <= ele) {
            st.pop();
            count++;
        }

        // if a taller person remains, that one is also visible
        if (!st.empty())    count++;

        ans[i] = count;
        st.push(ele);        // push current height

    }

    return ans;

}



int main() {

    vector<int> arr = {10, 6, 8, 5, 11, 9};

    
    vector<int> result = canSeePersonsCount(arr);
    cout << "Visible persons count: ";

    for (int x : result)    cout << x << " ";
    cout << endl;

    return 0;
}