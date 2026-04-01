#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    queue<int>q;

    cout << q.size() << endl;      // to get size of queue

    q.push(10);                    // to push in queue
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.size() << endl;

    q.pop();                       // removes front element
    q.pop();

    cout << q.size() << endl;
    cout << q.front() << endl;     // to access front of queue
    cout << q.back() << endl;     // to access rear of queue

    cout << endl;


// -----------------------------------------------------------------------------
// to print the whole queue
// here we lose elements during popping (same as stack)   OR
// we can also reuse the existing queue by poopping from from front and push in same queue


    int n = q.size();              // store current size of queue

    for(int i = 0; i < n; i++){
        int ele = q.front();       // access front element

        cout << q.front() << " ";  // print front element

        q.pop();                   // remove front element
        q.push(ele);               // push it back to maintain order
    }

    cout << endl;



 return 0;

}