#include <bits/stdc++.h>
using namespace std;

// leetcode Q->234      Check a LL is pallindrome or not 


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 🔹 Reverse Linked List (Iterative)


Node* reverseIterative(Node* head) {

    Node* prev = NULL;
    Node* curr = head;
    Node* nextt = NULL;

    while(curr != NULL) {

        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }

    return prev;
}

// 🔹 Check Palindrome

bool isPalindrome(Node* head) {

    if(head == NULL || head->next == NULL)  return true;

    Node* slow = head;
    Node* fast = head;

    // Find middle (left middle for even length)
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse second half
    Node* newHead = reverseIterative(slow->next);
    slow->next = newHead;

    Node* firstHalf = head;
    Node* secondHalf = newHead;

    // Compare both halves
    while(secondHalf != NULL) {

        if(secondHalf->val != firstHalf->val)    return false;

        secondHalf = secondHalf->next;
        firstHalf  = firstHalf->next;
    }

    return true;
}



void printList(Node* head) {

    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    // Longer Palindrome List:
    // 1 → 3 → 5 → 7 → 9 → 7 → 5 → 3 → 1

    Node* n1 = new Node(1);
    Node* n2 = new Node(3);
    Node* n3 = new Node(5);
    Node* n4 = new Node(7);
    Node* n5 = new Node(9);
    Node* n6 = new Node(7);
    Node* n7 = new Node(5);
    Node* n8 = new Node(3);
    Node* n9 = new Node(1);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;

    cout << "List: ";
    printList(n1);

    if(isPalindrome(n1))    cout << "It is a Palindrome" << endl;
    else                    cout << "Not a Palindrome" << endl;

    return 0;
}
