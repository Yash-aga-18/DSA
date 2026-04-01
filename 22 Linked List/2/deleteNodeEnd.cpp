#include <bits/stdc++.h>
using namespace std;

// leetcode Q->19      Delete nth node from end

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Helper function to print list
void printList(Node* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// I used to calculate posn from starting then delete, it is very basic 
Node* removeNthFromEnd1(Node* head, int n) {    

    int len = 0;
        
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }

    int target = len-n;

    if(target == 0){     
        
        Node* toDelete = head;
        head = head->next;

        delete toDelete;
    }


    else {

        Node* temp1 = head;
        for(int i=0; i<target-1; i++){
            temp1 = temp1->next;
        }

        Node* toDelete = temp1->next;
        temp1->next = toDelete->next;

        delete toDelete;
    }
    
    return head;

}


Node* removeNthFromEnd2(Node* head, int n) {

    Node* slow = head;
    Node* fast = head;

    // Move fast n steps
    for(int i = 0; i < n; i++){
        fast = fast->next;
    }

    // If fast is NULL → remove head
    if(fast == NULL){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return head;
    }

    // Move both until fast reaches tail
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    Node* toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;

    return head;
}



int main() {

    // Creating list: 10 → 20 → 30 → 40 → 50
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;

    Node* head = a;

    cout << "Original List: ";
    printList(head);

    int n = 3;  // remove 2nd node from end (should remove 40)

    head = removeNthFromEnd2(head, n);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}
