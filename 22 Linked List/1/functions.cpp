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


void display(Node *head){
    
    Node *temp = head;
    while(temp != NULL){
        cout<< temp->val <<endl;
        temp = temp->next;
    }
    cout<<endl;

}


int size(Node *head){
    
    Node *temp = head;
    int count = 0;

    while(temp != NULL){
        
        temp = temp->next;
        count++; 
    }

    return count;

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
    
    
    Node *head = a;

    display(head);               //  to print the whole LL
    cout<<size(head)<< endl;     //  to print the whole LL

    
 return 0;

}