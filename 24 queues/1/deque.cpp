#include <bits/stdc++.h>
using namespace std;

// make a deque( doubly ended queue)    both push/back is allowed from both front/rear
// it is advised to use doubly LL  OR u can use in-built also

class Node{
public:

    int val;        // stores value of node
    Node *prev;     // pointer to previous node
    Node *next;     // pointer to next node

    Node(int val){
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};


class mydeque{
public:

    Node* head;     // pointer to first node
    Node* tail;     // pointer to last node
    int count;      // number of elements

    mydeque(){
        head = tail = NULL;
        count = 0;
    }

    // insert element at back
    void pushBack(int val){
        Node *temp = new Node(val);

        if(count == 0)      head = tail = temp;      // first element

        else{
            tail->next = temp;       // connect old tail to new node
            temp->prev = tail;       // connect new node to old tail
            tail = temp;             // update tail
        }

        count++;
    }
    
    // insert element at front
    void pushFront(int val){
        Node *temp = new Node(val);

        if(count == 0)      head = tail = temp;      // first element

        else{
            temp->next = head;       // new node points to old head
            head->prev = temp;       // old head points back to new node
            head = temp;             // update head
        }

        count++;
    }
    
    // remove element from front
    void popFront(){
        
        if(count == 0)          return;                  // empty deque
        
        if(count == 1){              // only one element
            delete head;
            head = tail = NULL;
            count--;
            return;
        }
        
        Node *toDelete = head;

        head = head->next;           // move head forward
        head->prev = NULL;           // remove backward link
        
        delete toDelete;
        count--;
    }
    
    // remove element from back
    void popBack(){
        
        if(count == 0)          return;                  // empty deque
        
        if(count == 1){              // only one element
            delete tail;
            head = tail = NULL;
            count--;
            return;
        }
        
        Node *toDelete = tail;

        tail = tail->prev;           // move tail backward
        tail->next = NULL;           // remove forward link
        
        delete toDelete;
        count--;
    }

    int front(){
        if(count == 0)  return -1;

        else            return head->val; 
    }
    
    int back(){
        if(count == 0)  return -1;

        else            return tail->val; 
    }

    void display(){
        Node *temp = head;

        while(temp){
            cout<<  temp->val <<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    int size(){
        return count;
    }


};



int main()
{
    
    mydeque dq;                  // create deque

    // push elements at back
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);

    // push elements at front
    dq.pushFront(5);
    dq.pushFront(1);

    cout << "Deque after push operations: ";
    dq.display();

    // check front and back
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;

    // pop from front
    dq.popFront();
    cout << "After popFront: ";
    dq.display();

    // pop from back
    dq.popBack();
    cout << "After popBack: ";
    dq.display();

    // more operations
    dq.pushFront(100);
    dq.pushBack(200);

    cout << "After more insertions: ";
    dq.display();

    return 0;
}