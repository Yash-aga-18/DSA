#include <bits/stdc++.h>
using namespace std;

// Stock Span Problem
/*
starting from day i and going backwards, count how many consecutive days have prices ≤ arr[i].

INPUT: {100,80,60,81,70,60,75,85};
Day	Price	Span	Explanation
0	 100	 1	     No previous day
1	 80	     1	     100 > 80
2	 60	     1	     80 > 60
3	 81	     3	     81 ≥ 60, 80
4	 70	     1	     81 > 70
5	 60	     1	     70 > 60
6	 75	     3	     75 ≥ 60, 70
7	 85	     6	     85 ≥ 75, 60, 70, 81, 60

*/

int main() {

    vector<int> arr = {100,80,60,81,70,60,75,85};
    int n = arr.size();

    stack<int> st;
    vector<int> prev(n);


    st.push(0);              // store index of first element
    prev[0] = 1;             // span of first element is always 1

    for(int i = 1; i < n; i++) {

        int ele = arr[i];

        // remove all smaller or equal prices
        while(!st.empty() && arr[st.top()] <= ele)      st.pop();

        if(st.empty())      prev[i] = i + 1;            // span extends to beginning
        else                prev[i] = i - st.top();     // distance from previous greater price

        st.push(i);              // push current index
    }

    cout << "Stock Span: ";
    for(int x : prev)   cout << x << " ";


    return 0;
}