#include <bits/stdc++.h>
using namespace std;

class Node{
 public:

    int val;        // it stores the current value
    Node *next;     // it stores the address of next elemnt
    Node *prev;     // it stores the address of prev elemnt

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }

};

void display(Node *head){

    while(head!=NULL){
        cout<<head->val<< " ";
        head = head->next;
    }

}



int main()
{
    
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    
    
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e; 
    
    e->prev = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;
    a->prev = NULL;
    
    Node *head = a;

    display(head);


 return 0;

}