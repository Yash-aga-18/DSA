#include <bits/stdc++.h>
using namespace std;


// function to insert element at bottom of stack
void push_bottom(stack<int> &st, int x){

    // base case: if stack empty push element
    if(st.empty()){
        st.push(x);
        return;
    }

    int top_val = st.top();   // store top
    st.pop();                 // remove top
    
    push_bottom(st, x);       // recursively reach bottom

    st.push(top_val);         // restore elements
}


// function to reverse stack using recursion
void rever(stack<int> &st){

    // base case: only one element left
    if(st.size() == 1) return;

    int x = st.top();   // store top
    st.pop();           // remove top

    rever(st);          // reverse remaining stack
    
    push_bottom(st, x); // insert removed element at bottom
}



int main(){

    stack<int> st;

    // push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // reverse stack
    rever(st);

    // print stack
    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}