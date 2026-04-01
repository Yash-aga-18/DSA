#include <bits/stdc++.h>
using namespace std;

class Node{
 public:

    int val;      // it stores the current value
    Node *next;     // it stores the address of next elemnt

    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};



int main()
{
    
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);

/*
    till here what is done -->
        new node is created (10,NULL)  then node a is created stores the address of that node  eg-> a stores x100 
        new node is created (20,NULL)  then node b is created stores the address of that node  eg-> b stores x300 
        new node is created (30,NULL)  then node c is created stores the address of that node  eg-> c stores x500 
        new node is created (40,NULL)  then node d is created stores the address of that node  eg-> d stores x900 
    
*/

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    a->next = b;
    b->next = c;
    c->next = d;
    // d->next = NULL;  // no need to write because constructor already sets it

/*
    till here what is done -->
        it goes to address of node A  and from there it update the value of next with address of B
        it goes to address of node B  and from there it update the value of next with address of C
        it goes to address of node C  and from there it update the value of next with address of D

*/

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

    cout<<a->val <<endl;
    cout<<(a->next)->val <<endl;
    cout<< endl;


 return 0;

}