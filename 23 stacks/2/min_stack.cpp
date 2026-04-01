#include <bits/stdc++.h>
using namespace std;

// leetcode Q->155
// Design a stack that do push, pop, top,  get minimum element in constant time.



/*----------------------------------------------------
Method 1 : Brute Force
TC: push O(1), pop O(1), top O(1), getMin O(n)
SC: O(n)
----------------------------------------------------*/

class MinStack1 {
public:
    stack<int> st;

    void push(int val) {
        st.push(val);
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {

        stack<int> temp = st;
        int mn = INT_MAX;

        // scan whole stack
        while(!temp.empty()) {
            mn = min(mn, temp.top());
            temp.pop();
        }

        return mn;
    }
};


/*----------------------------------------------------
Method 2 : Using Two Stacks
TC: O(1) for all operations
SC: O(n)
----------------------------------------------------*/

class MinStack2 {
public:

    stack<int> st;
    stack<int> min_st;

    void push(int val) {

        st.push(val);

        if(min_st.empty())  min_st.push(val);
        else                min_st.push(min(val, min_st.top()));

    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};


/*----------------------------------------------------
Method 3 : Using Vector
TC: O(1)
SC: O(n)
----------------------------------------------------*/

class MinStack3 {
public:

    vector<int> st;

    void push(int val) {
        st.push_back(val);
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {

        int ans = INT_MAX;

        for(int i=0; i<st.size(); i++){
            ans = min(ans, st[i]);
        }

        return ans;
    }
};


/*----------------------------------------------------
Method 4 : Mathematical Encoding Trick
TC: O(1)
SC: O(n) (no extra stack)
----------------------------------------------------*/

class MinStack4 {
public:

    stack<long long> st;   // stack stores normal values or encoded values
    int minVal;            // current minimum element

    void push(int val) {

        if(st.empty()) {

            st.push(val);
            minVal = val;           // first element becomes minimum
        }

        else if(val >= minVal)    st.push(val);           // normal push if value >= current min

        else {

            // encode value so previous minimum can be restored later
            long long encoded = 2LL * val - minVal;
            st.push(encoded);

            minVal = val;           // update new minimum
        }
    }

    void pop() {

        long long topVal = st.top();
        st.pop();

        // if encoded value appears, restore previous minimum
        if(topVal < minVal)        minVal = 2LL * minVal - topVal;
    
    }

    int top() {

        long long topVal = st.top();

        // if encoded value, actual top element is current minimum
        if(topVal < minVal)      return minVal;

        return topVal;              // normal value
    }

    int getMin() {

        return minVal;              // return current minimum
    }

};


/*----------------------------------------------------
Main Function
----------------------------------------------------*/

int main() {

    cout << "Testing Method 4 (Encoding Trick)\n";

    MinStack4 ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);

    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

    ms.pop();

    cout << "After pop\n";
    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.getMin() << endl;

}