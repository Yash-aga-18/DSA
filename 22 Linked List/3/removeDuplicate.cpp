#include <bits/stdc++.h>
using namespace std;

// leetcode Q->83

// Given the head of a sorted linked list, delete all duplicates such that 
// each element appears only once. Return the linked list sorted as well.

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to remove duplicates from sorted list
Node* deleteDuplicates(Node* head) {

    if(head == NULL || head->next == NULL)  return head;

    Node* curr = head;

    while(curr != NULL && curr->next != NULL){

        // If duplicate found
        if(curr->val == curr->next->val){

            Node* toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
        
        else {
            curr = curr->next;
        }
    }

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

    // Create sorted list:
    // 1 → 1 → 1 → 2 → 3 → 3 → 4 → 4 → 5
    Node* a = new Node(1);
    Node* b = new Node(1);
    Node* c = new Node(1);
    Node* d = new Node(2);
    Node* e = new Node(3);
    Node* f = new Node(3);
    Node* g = new Node(4);
    Node* h = new Node(4);
    Node* i = new Node(5);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;

    Node* head = a;

    cout << "Original List: ";
    printList(head);


    head = deleteDuplicates(head);


    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
