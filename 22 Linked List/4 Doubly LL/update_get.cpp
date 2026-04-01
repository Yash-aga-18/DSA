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



    int getValue(int idx){

        if(idx < 0 || idx>=(size))      return -1;
        else if(idx == 0 )              return head->val;
        else if(idx == size-1 )         return tail->val;

        Node *temp = head;
        for(int i=1; i<=idx; i++) {
            temp = temp->next;
        }
        return temp->val;
        
    }


    void updateValue(int idx, int val){

        if(idx < 0 || idx>=size)        cout<<"invalid idx";
        else if(idx == 0 )              head->val = val;
        else if(idx == size-1 )         tail->val = val;

        else{
            Node *temp = head;
            for(int i=1; i<=idx; i++) {
                temp = temp->next;
            }
            temp->val = val; 
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
    dll.insertAt(0,500);
    dll.insertAt(3,700);
    dll.display();
    

    dll.updateValue(0,100);
    dll.updateValue(5,200);
    dll.updateValue(3,300);
    dll.display();


    cout << dll.getValue(0) << endl;
    cout << dll.getValue(3) << endl;
    cout << dll.getValue(10) << endl;   // invalid test



 return 0;

}