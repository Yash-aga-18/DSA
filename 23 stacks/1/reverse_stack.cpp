#include <bits/stdc++.h>
using namespace std;


// Method 1: Reverse stack using vector
void rever1(stack<int> &st){

    vector<int> v;

    // move all elements from stack to vector
    while(!st.empty()){
        v.push_back(st.top());
        st.pop();
    }

    // push elements back to stack (reversed order)
    for(int i = 0; i < v.size(); i++){
        st.push(v[i]);
    }
}


// Method 2: Reverse stack using another stack
void rever2(stack<int> &st){

    stack<int> temp1;
    stack<int> temp2;

    // move elements to temporary stack 1
    while(st.size()>0 ){
    
        temp1.push(st.top());
        st.pop();
    }
    
    // move elements to temporary stack 2
    while(temp1.size()>0 ){
    
        temp2.push(temp1.top());
        temp1.pop();
    }

    // move back to original stack
    while(temp2.size()>0 ){
    
        st.push(temp2.top());
        temp2.pop();
    }
    
}


int main(){

    stack<int> st;

    // push elements into stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    // reverse using vector
    rever1(st);

    // reverse again using extra stack
    rever2(st);

    // print stack
    while(st.size()>0 ){
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}