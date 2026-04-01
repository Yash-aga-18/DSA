#include <bits/stdc++.h>
using namespace std;

class Node{
 public:

    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};

class LinkedList{
 public: 

    Node *head;
    Node *tail;
    int size;

    LinkedList(){   // default constructor
        head = tail = NULL;
        size = 0;
    }

    void insertAtHead(int val){
        Node *temp = new Node(val);
        
        if(size == 0)   head = tail = temp;
        
        else{ 
            temp->next = head;
            head = temp;
        }
        
        size++;
    }

    void insertAtTail(int val){
        Node *temp = new Node(val);
        
        if(size == 0)   head = tail = temp;
        
        else{ 
            tail->next = temp; 
            tail = temp;
        }
        
        size++;
    }
    
    void insertAt(int idx, int val){

        if(idx < 0 || idx>(size))    cout<<"Invalid idx";
        else if(idx == 0 )           insertAtHead (val);
        else if(idx == size )        insertAtTail (val);

        else {
            Node *temp = new Node(val);            
            
            Node *t = head;                 // t is pointer which pointed to just prev idx
            for(int i = 0; i< idx-1; ++i){
                t = t->next;
            }
            
            temp->next = t->next;
            t->next = temp;
            
            size++;
        }
        
    }

    int getValue(int idx){

        if(idx < 0 || idx>=size)        return -1;
        else if(idx == 0 )              return head->val;
        else if(idx == size-1 )         return tail->val;

        Node *temp = head;
        for(int i=1; i<=idx; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void display(){

        Node *temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }


};



int main()
{
    
    LinkedList ll;

    ll.insertAtTail(10);    
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);    
    ll.insertAt(0,50);
    ll.insertAt(3,70);
    ll.display();

    cout<<ll.getValue(3)<< endl;



 return 0;

}