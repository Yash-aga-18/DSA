#include <bits/stdc++.h>
using namespace std;

class Node{
 public:

    int val;        // it stores the current value
    Node *next;     // it stores the address of next elemnt

    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};


int main()
{
    
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    cout<<a.val<<endl;

    // cout<<a.next;    // initially it stores the garbage value until we declared in constructer
    // to save from it we initally put NULL
    
    
    // forming the LL
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;       // no need to write as by default in constructor we save to NULL for each node 

    // to get the value of b 
    
    cout<<    b.val         <<endl;
    cout<< (*(a.next)).val  << endl;
    cout<<  (a.next)->val << endl;    // it is more preffered to write like this

    cout<< ( (a.next)->next)->val << endl;    // it gives the value of c
    cout<< ( (a.next)->next->next)->val << endl;    // it gives the value of d


    Node temp = a;      // we make a new node having replica of Node a 
    while(1){

        cout<<temp.val<< endl;
        if(temp.next == NULL)   break;
        
        temp = *(temp.next);        //now it just replace the existing value with next value 
    }





 return 0;

}