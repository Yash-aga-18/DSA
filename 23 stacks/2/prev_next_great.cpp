#include <bits/stdc++.h>
using namespace std;

// print the next greatest elemnt 

int main()
{
    vector<int> arr = {2,4,2,3,7,6,8};
    int n = arr.size();

    stack<int> st;

    st.push(arr[n-1]);
    arr[n-1] = -1;

    for(int i = n-2; i >= 0; i--) {

        int ele = arr[i];

        while(!st.empty() && st.top() <= ele)   st.pop();
    
        int nextGreater;

        if(st.empty())  nextGreater = -1;
        else            nextGreater = st.top();

        st.push(ele);

        arr[i] = nextGreater;

    }

    for(int x : arr)    cout << x << " ";
}