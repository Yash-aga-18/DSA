#include <bits/stdc++.h>
using namespace std;

// leetcode Q->141  determine if the linked list has a cycle in it.

// Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
// Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Floyd’s Cycle Detection Algorithm
bool hasCycle(Node* head) {

    // If list is empty or has only one node without self-loop
    if(head == NULL || head->next == NULL)      return false;

    Node* slow = head;
    Node* fast = head;

    // Move slow by 1 step and fast by 2 steps
    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        // If they meet → cycle exists
        if(slow == fast)    return true;
    }

    // If fast reaches NULL → no cycle
    return false;
}

int main() {

    // Create nodes
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    // Normal Linked List
    a->next = b;
    b->next = c;
    c->next = d;

    Node* head = a;

    if(hasCycle(head))  cout << "Cycle Present--> Yes" << endl;
    else                cout << "Cycle Present--> No" << endl;

    // Create a cycle (d → b)
    d->next = b;

    if(hasCycle(head))  cout << "Cycle Present After Creating Loop--> Yes" << endl;
    else                cout << "Cycle Present After Creating Loop--> No" << endl;

    return 0;
}
