#include <bits/stdc++.h>
using namespace std;

// Find:
// 1. First middle (before)
// 2. Second middle (after / default)


// ---------------- NODE ----------------
class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};


// ---------------- FUNCTION ----------------
// firstMiddle = true  → first middle (before)
// firstMiddle = false → second middle (after)

Node* findMiddle(Node* head, bool firstMiddle) {

    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast;

    if (firstMiddle)    fast = head->next;   // ⭐ first middle
    else                fast = head;         // ⭐ second middle

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// ---------------- PRINT ----------------
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


// ---------------- MAIN ----------------
int main()
{
    // Creating list: 10 → 20 → 30 → 40 → 50 → 60
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    Node* head = a;

    cout << "Linked List: ";
    printList(head);


    // ---------------- LOGIC ----------------
    Node* beforeMid = findMiddle(head, true);   // first middle
    Node* afterMid  = findMiddle(head, false);  // second middle

/*   For odd length linked list, there is only ONE middle. So both: will return same node
    findMiddle(head, true)
    findMiddle(head, false)

*/

    // ---------------- OUTPUT ----------------
    cout << "Before Middle: " << beforeMid->val << endl;
    cout << "After Middle: "  << afterMid->val  << endl;

    return 0;
}