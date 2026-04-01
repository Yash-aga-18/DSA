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

    void insertAtTail(int val){
        Node *temp = new Node(val);
        
        if(size == 0)   head = tail = temp;
        
        else{ 
            tail->next = temp;
            tail = temp; 
        }
        
        size++;
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
    ll.display();
    
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.display();

    cout<<"size is --> "<<ll.size;


 return 0;

}