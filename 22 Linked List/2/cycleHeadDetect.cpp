#include <bits/stdc++.h>
using namespace std;

// leetcode Q->142  determine the head of cycle.

// Given the head of a linked list, return the node where the cycle begins. 
// If there is no cycle, return null.

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to detect starting node of cycle
Node* detectCycle(Node* head) {

    if(head == NULL || head->next == NULL)  return NULL;

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect if cycle exists
    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){

            // Step 2: Find cycle starting node
            Node* temp = head;

            while(temp != slow){
                temp = temp->next;
                slow = slow->next;
            }

            return temp;   // cycle start

        }

    }

    return NULL;   // no cycle
}


int main() {

    // Create nodes
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);

    // Normal list
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node* head = a;

    // No cycle case
    Node* result = detectCycle(head);

    if(result == NULL)     cout << "No cycle detected." << endl;
    else                   cout << "Cycle starts at node: " << result->val << endl;

    // Create a cycle: e -> c
    e->next = c;

    result = detectCycle(head);

    if(result == NULL)  cout << "No cycle detected." << endl;
    else                cout << "Cycle starts at node: " << result->val << endl;

    return 0;
}