#include <bits/stdc++.h>
using namespace std;

// remove the the elemnts stored at even indices(0-based indexing)



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



int main()
{
    
    queue<int> q;                  // create queue

    // inserting elements into queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    display(q);                    // print original queue

    int count = 0;
    int n = q.size();
    
    for(int i=0; i<n; i++){

        if(count%2 == 0)    q.pop();
        
        else{
            int ele = q.front();
            q.pop();
            q.push(ele);    // we again push the elemnt to last
        }

        count ++;
    }
    

    display(q);                    // print reversed queue
    
    return 0;
}