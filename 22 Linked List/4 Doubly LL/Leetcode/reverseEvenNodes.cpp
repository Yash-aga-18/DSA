#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2074
// Reverse Nodes in Even Length Groups

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Reverse exactly k nodes and connect to nextGroup
Node* reverseKNodes(Node* head, int k, Node* nextGroup) {

    Node* prev = nextGroup;
    Node* curr = head;
    Node* nextt = NULL;

    while(k > 0) {

        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;

        k--;
    }

    return prev;   // new head of reversed group
}

Node* reverseEvenLengthGroups(Node* head) {

    if(head == NULL) return head;

    Node* curr = head;
    Node* prevGroupTail = NULL;

    int groupSize = 1;

    while(curr != NULL){

        Node* groupStart = curr;
        int count = 0;

        // Count actual nodes in this group
        while(curr != NULL && count < groupSize){
            curr = curr->next;
            count++;
        }

        // If group length is even → reverse
        if(count % 2 == 0){

            Node* newHead = reverseKNodes(groupStart, count, curr);

            if(prevGroupTail != NULL)
                prevGroupTail->next = newHead;
            else
                head = newHead;

            prevGroupTail = groupStart;
        }
        else{

            // Move prevGroupTail to end of group
            prevGroupTail = groupStart;
            for(int i = 1; i < count; i++){
                prevGroupTail = prevGroupTail->next;
            }
        }

        groupSize++;
    }

    return head;
}

// Helper function to print list
void printList(Node* head) {

    while(head != NULL){
        cout << head->val;
        if(head->next != NULL) cout <<" ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Example:
    // 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;

    Node* head = a;

    cout << "Original List:\n";
    printList(head);

    head = reverseEvenLengthGroups(head);

    cout << "\nAfter Reversing Even Length Groups:\n";
    printList(head);

    return 0;
}