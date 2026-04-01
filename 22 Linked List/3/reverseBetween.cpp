#include <bits/stdc++.h>
using namespace std;

// leetcode Q->92

// Given the head and two integers left and right where left <= right, 
// reverse the nodes from position left to position right, and return the reversed list.


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// 🔹 Reverse from head to tail (inclusive)

Node* reverseList(Node* head, Node* tail) {

    Node* prev = NULL;
    Node* curr = head;
    Node* nextt = NULL;

    // Reverse until we cross tail
    while(prev != tail){

        nextt = curr->next;   // store next
        curr->next = prev;    // reverse link
        prev = curr;          // move prev
        curr = nextt;         // move curr
    }

    return prev;   // new head of reversed portion

}


Node* reverseBetween(Node* head, int left, int right) {

    if(head == NULL || left == right)   return head;


    Node* temp1 = head;
    Node* beforeLeft = NULL;

    // Move temp1 to 'left' position
    for(int i = 1; i < left; i++){
        beforeLeft = temp1;      // node before left
        temp1 = temp1->next;     // move forward
    }

    Node* temp2 = temp1;

    // Move temp2 to 'right' position
    for(int i = left; i < right; i++){
        temp2 = temp2->next;
    }
    Node* afterRight = temp2->next;


    // Reverse from temp1 to temp2
    Node* newHead = reverseList(temp1, temp2);


    // Reconnect left side
    if(beforeLeft != NULL)  beforeLeft->next = newHead;
    else                    head = newHead;  // if left == 1

    // Connect right side (IMPORTANT)
    temp1->next = afterRight;


    return head;

}



void printList(Node* head) {

    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


int main() {

    // Create list: 1 → 2 → 3 → 4 → 5 → 6 → 7
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;

    cout << "Original List: ";
    printList(n1);

    int left = 3;
    int right = 6;

    Node* result = reverseBetween(n1, left, right);

    cout << "After Reversing from " << left << " to " << right << ": "<< endl;
    printList(result);

    return 0;
    
}
