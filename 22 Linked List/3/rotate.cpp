#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to rotate list to the right by k places
Node* rotateRight(Node* head, int k) {

    if(head == NULL || head->next == NULL)  return head;

    // Step 1: Find length and tail
    int len = 0;
    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
        len++;
    }
    len++;        //to count the tail node also


    // Step 2: Reduce k
    k = k % len;
    if(k == 0)      return head;

    
    Node* temp = head;
    for(int i = 0; i < len - k - 1; i++){
        temp = temp->next;
    }
    
    tail->next = head;
    head = temp->next;
    temp->next = NULL;

    return head;
    
}

// Helper function to print list
void printList(Node* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create list: 1 → 2 → 3 → 4 → 5
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node* head = a;

    cout << "Original List: ";
    printList(head);

    int k = 2;

    head = rotateRight(head, k);

    cout << "After Rotating by " << k << ": ";
    printList(head);

    return 0;
}
