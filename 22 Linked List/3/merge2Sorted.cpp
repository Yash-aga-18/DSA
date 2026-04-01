#include <bits/stdc++.h>
using namespace std;

// leetcode Q->21   Merge 2 Sorted LL
// Merge the two lists into one sorted list.Return the head of the merged linked list



class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Merge two sorted linked lists
Node* mergeTwoLists(Node* list1, Node* list2) {

    Node* tempA = list1;
    Node* tempB = list2;

    // Dummy node
    Node* c = new Node(-1);
    Node* tempC = c;

    while(tempA != NULL && tempB != NULL){

        if(tempA->val <= tempB->val){
            tempC->next = tempA;
            tempA = tempA->next;
        }
        else{
            tempC->next = tempB;
            tempB = tempB->next;
        }

        tempC = tempC->next;
    }

    // Attach remaining nodes
    if(tempA != NULL)       tempC->next = tempA;
    else                    tempC->next = tempB;

    return c->next;   // skip dummy

    
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

    // Create first sorted list: 1 → 3 → 5
    Node* a1 = new Node(1);
    Node* a2 = new Node(3);
    Node* a3 = new Node(5);

    a1->next = a2;
    a2->next = a3;

    // Create second sorted list: 2 → 4 → 6
    Node* b1 = new Node(2);
    Node* b2 = new Node(4);
    Node* b3 = new Node(6);

    b1->next = b2;
    b2->next = b3;

    cout << "List 1: ";
    printList(a1);

    cout << "List 2: ";
    printList(b1);

    Node* merged = mergeTwoLists(a1, b1);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}
