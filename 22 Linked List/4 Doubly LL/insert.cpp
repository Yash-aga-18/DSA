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



class DoubleLinkedList{
 public: 

    Node *head;
    Node *tail;
    int size;

    DoubleLinkedList(){   // default constructor
        head = tail = NULL;
        size = 0;
    }

    void insertAtHead(int val){
        Node *temp = new Node(val);
        
        if(size == 0)   head = tail = temp;
        
        else{ 
            temp->next = head;
            head->prev = temp;

            head = temp;
        }
        
        size++;
    }


    void insertAtTail(int val){
        Node *temp = new Node(val);
        
        if(size == 0)   head = tail = temp;
        
        else{
            tail->next = temp;
            temp->prev = tail; 

            tail = temp;
        }
        
        size++;
    }


    
    void insertAt(int idx, int val){

        if(idx < 0 || idx > size){
            cout<<"Invalid idx"<<endl;
            return;
        }
        
        else if(idx == 0 )           insertAtHead (val);
        else if(idx == size )        insertAtTail (val);

        else {
            Node *temp = new Node(val);            
            
            Node *t = head;                 // t is pointer which pointed to just prev idx
            for(int i = 1; i<idx; ++i){
                t = t->next;
            }
            
            temp->next = t->next;
            t->next = temp;

            temp->prev = t;
            temp->next->prev = temp;
            
            size++;
        }
        
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
    
    DoubleLinkedList dll;

    dll.insertAtTail(10);    
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);
    dll.display();
    
    dll.insertAt(0,50);
    dll.display();
    
    dll.insertAt(5,60);
    dll.display();

    dll.insertAt(3,70);
    dll.display();
    
    dll.insertAt(4,80);
    dll.display();


 return 0;

}
