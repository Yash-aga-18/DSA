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


    void deleteAtHead(){

        if(size == 0) {      
            cout<<"error! empty LL"<<endl;
            return;
        }        
        
        Node *toDelete = head;

        if(size == 1)   head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }

        delete toDelete;

        size--;
    }

    
    void deleteAtTail(){

        if(size == 0) {      
            cout<<"error! empty LL"<<endl;
            return;
        }

        Node *toDelete = tail;
        
        if(size == 1)       head = tail = NULL;
        else {
            
            tail = tail->prev;
            tail->next = NULL;
        }
        
        delete toDelete;
        size--;
    }
    
    
    
    void deleteAt(int idx){
        
        if(idx <0 || idx>=size) {      
            cout<<"error! invalid idx"<<endl;
            return;
        }
        
        else if(idx == 0)                deleteAtHead();
        else if(idx == (size-1))         deleteAtTail();
        
        else {
            Node *temp = head;
            
            // reach prev last node
            for(int i = 1; i < idx; ++i){
                temp = temp->next;
            }
            
            Node *toDelete = temp->next;

            temp->next = toDelete->next;
            toDelete->next->prev = temp;

            delete toDelete;

            size--;
        }
        
    }    



};



int main()
{
    DoubleLinkedList dll;

    // Build list
    dll.insertAtTail(10);    
    dll.insertAtTail(20);
    dll.insertAtTail(30);
    dll.insertAtTail(40);    
    dll.insertAt(0,50);
    dll.insertAt(5,60);
    dll.insertAt(3,70);
    dll.insertAt(4,80);

    cout << "Initial List: ";
    dll.display();

    // 1️⃣ Delete Head
    cout << "Delete Head:\n";
    dll.deleteAtHead();
    dll.display();


    // 2️⃣ Delete Tail
    cout << "Delete Tail:\n";
    dll.deleteAtTail();
    dll.display();


    // 3️⃣ Delete Middle (index 2)
    cout << "Delete Middle (index 2):\n";
    dll.deleteAt(2);
    dll.display();


    // 4️⃣ Delete Last Element using deleteAt
    cout << "Delete Last Index:\n";
    dll.deleteAt(dll.size - 1);
    dll.display();


  return 0;
  
}
