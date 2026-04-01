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

    void deleteAtHead(){

        if(size == 0) {      
            cout<<"error! empty LL"<<endl;
            return;
        }        
        
        Node *toDelete = head;

        if(size == 1)   head = tail = NULL;
        else            head = head->next;

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
            Node *temp = head;
            
            // reach second last node
            for(int i = 1; i < size-1; ++i){
                temp = temp->next;
            }
            
            temp->next = NULL;
            temp = tail;
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
            delete toDelete;

            size--;
        }
        
    }


};



int main()
{
    
    LinkedList ll;

    



 return 0;

}