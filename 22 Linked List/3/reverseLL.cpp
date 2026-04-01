#include <bits/stdc++.h>
using namespace std;

// leetcode Q->206  Reverse the Linked List


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 🔹 1️⃣ ITERATIVE APPROACH (O(1) Space)

Node* reverseIterative(Node* head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* nextt = NULL;

    while(curr != NULL) {

        nextt = curr->next;   // store next
        curr->next = prev;    // reverse link
        prev = curr;          // move prev
        curr = nextt;         // move curr
    }

    return prev;
    
}


// 🔹 2️⃣ RECURSIVE APPROACH (O(n) Stack Space)

Node* reverseRecursive(Node* head) {

    if(head == NULL || head->next == NULL)  return head;

    Node* newHead = reverseRecursive(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;


}



void printList(Node* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    // Create list: 1 → 2 → 3 → 4 → 5
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    cout << "Original List: ";
    printList(n1);

    // 🔹 Iterative Reverse
    Node* reversed1 = reverseIterative(n1);

    cout << "Reversed (Iterative): ";
    printList(reversed1);

    // 🔹 Reverse Again Using Recursive (to restore original order)
    Node* reversed2 = reverseRecursive(reversed1);

    cout << "Reversed (Recursive): ";
    printList(reversed2);

    return 0;
}

/*
Suppose the list is:  1 -> 2 -> 3 -> 4 -> NULL

When recursion reaches the last node: reverseList(4)

It returns:  4 -> NULL

Then the function goes backwards in the call stack.
Now we are at node 3.
But because recursion reversed the rest, we now have:  3 -> 4 -> NULL
And newHead is 4.

2️⃣ First Important Line
head->next->next = head;

Suppose
head = 3
head->next = 4

So this line becomes  4->next = 3

Now the link becomes:
3 -> 4
4 -> 3

Which temporarily looks like:
3 <-> 4

So this line actually reverses the direction.

3️⃣ Second Important Line
head->next = NULL;

So we remove the old forward link:
3 -> NULL

Now the list becomes
4 -> 3 -> NULL


*/