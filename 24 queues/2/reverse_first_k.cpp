#include <bits/stdc++.h>
using namespace std;

// function to display queue without destroying its order
void display(queue<int> &q){
    
    int n = q.size();              
    
    for(int i = 0; i < n; i++){
        int ele = q.front();       
        
        cout << q.front() << " ";  
        
        q.pop();                  
        q.push(ele);            
    }
    
    cout << endl;
}


void reverse_q(queue<int> &q, int k){

    stack<int> st;                 // stack used to reverse queue
    
    int n = q.size();              // store size of queue
    
    // move k elements from queue → stack
    for(int i = 0; i < k; i++){
        int ele = q.front();       // get front element
        
        st.push(ele);              // push element into stack
        q.pop();                   // remove element from queue
    }


    // move k elements from stack → queue
    while(!st.empty()){
        int ele = st.top();        // get top element of stack
        
        q.push(ele);               // push back into queue
        st.pop();                  // remove from stack
    }

    // now just push all other emaining to back
    for(int i=0; i<(n-k); i++){
        int ele = q.front();
        q.push(ele);
        q.pop();
    }

}


int main() {
    
    queue<int> q;                  // create queue

    // inserting elements into queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    display(q);                    // print original queue
    
    reverse_q(q,2);

    display(q);                    // print reversed queue
    
    return 0;
}