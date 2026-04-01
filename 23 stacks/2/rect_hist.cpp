#include <bits/stdc++.h>
using namespace std;

// leetcode Q->84  Largest Rectangle in Histogram
// return the area of the largest rectangle in the histogram

// use of next smaller and previous smaller elements index

int main()
{
    vector<int> arr = {2,1,5,6,2,3};
    int n = arr.size();

    stack<int> st;

    vector<int> next_sm(n);
    vector<int> prev_sm(n);

    // NEXT SMALLER (RIGHT)

    st.push(n-1);          // store index of last element
    next_sm[n-1] = n;      // no smaller element on right

    for(int i = n-2; i >= 0; i--) {

        int ele = arr[i];

        // remove elements greater or equal to current
        while(!st.empty() && arr[st.top()] >= ele)      st.pop();
        
        if(st.empty())      next_sm[i] = n;        // no smaller element on right
        else                next_sm[i] = st.top(); // index of next smaller element

        st.push(i);                // push current index

    }

    while(!st.empty())      st.pop();                  // clear stack



    // PREVIOUS SMALLER (LEFT)

    st.push(0);                    
    prev_sm[0] = -1;               // no smaller element on left

    for(int i = 1; i < n; i++) {

        int ele = arr[i];

        // remove elements greater or equal to current
        while(!st.empty() && arr[st.top()] >= ele)      st.pop(); 

        if(st.empty())      prev_sm[i] = -1;       // no smaller element on left
        else                prev_sm[i] = st.top(); // index of previous smaller element

        st.push(i);  

    }

    cout << "next smaller: ";
    for(int x : next_sm) cout << x << " ";
    cout << endl;
    
    cout << "prev smaller: ";
    for(int x : prev_sm) cout << x << " ";
    cout << endl;
    

    vector<int> ans;
    int max_area = INT_MIN;

    for(int i=0; i<n; i++){

        int breadth = next_sm[i] - prev_sm[i] - 1; // width of rectangle
        int height = arr[i];

        int area = height * breadth;
        max_area = max(area, max_area);
        
        ans.push_back(area);

    }

    cout << "area for each bar: ";
    for(int x : ans) cout << x << " ";
    cout << endl;

    cout << "max area: " << max_area << endl;

 return 0;
}