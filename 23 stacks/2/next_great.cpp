#include <bits/stdc++.h>
using namespace std;

// print next greater and previous greater elements

int main()
{
    vector<int> arr = {2,4,2,3,7,6,8,1};
    int n = arr.size();

    stack<int> st;

    vector<int> next(n);
    vector<int> prev(n);

    // NEXT GREATER (RIGHT)

    st.push(arr[n-1]);      // last element has no element on right
    next[n-1] = -1;

    for(int i = n-2; i >= 0; i--) {

        int ele = arr[i];

        // remove all elements smaller or equal to current
        while(!st.empty() && st.top() <= ele)   st.pop();
        
        if(st.empty())  next[i] = -1;           // no greater element on right
        else            next[i] = st.top();     // nearest greater element

        st.push(ele);                           // push current element for future comparisons
    }

    while(!st.empty()) st.pop();                // clear stack 



    // PREVIOUS GREATER (LEFT)

    st.push(arr[0]);        // first element has no element on left
    prev[0] = -1;

    for(int i = 1; i < n; i++) {

        int ele = arr[i];

        // remove all elements smaller or equal to current
        while(!st.empty() && st.top() <= ele)   st.pop(); 

        if(st.empty())  prev[i] = -1;           // no greater element on left
        else            prev[i] = st.top();     // nearest greater element

        st.push(ele);                           // push current element
    }

    cout << "Next Greater: ";
    for(int x : next)       cout << x << " ";

    cout << endl;

    cout << "Prev Greater: ";
    for(int x : prev)       cout << x << " ";

 return 0;

}