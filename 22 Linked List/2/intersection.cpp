#include <bits/stdc++.h>
using namespace std;

// leetcode Q->160 
// Given the heads of two singly linked-lists headA and headB, 
// return the node at which the two lists intersect. 
// If the two linked lists have no intersection at all, return null.


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Helper function to print list
void printList(Node* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}


// Function to find intersection node
Node* getIntersectionNode2(Node* headA, Node* headB) {

    // If either list is empty, no intersection
    if(headA == NULL || headB == NULL)  return NULL;

    Node* t1 = headA;
    Node* t2 = headB;

    // Traverse until both pointers are equal
    // They will meet at intersection node or NULL
    while(t1 != t2){

        if(t1 == NULL)  t1 = headB; 
        else            t1 = t1->next;

        if(t2 == NULL)  t2 = headA;
        else            t2 = t2->next;
    
    }

    return t1;   // can be intersection node or at end they will both at NULL


}

Node *getIntersectionNode1(Node *headA, Node *headB) { 
        
    Node *tempA = headA;
    Node *tempB = headB;

    int lenA = 0; 
    int lenB = 0;

    while(tempA != NULL){
        tempA = tempA->next;
        lenA++;
    } 
    
    while(tempB != NULL){
        tempB = tempB->next;
        lenB++;
    } 

    tempA = headA;
    tempB = headB;

    if(lenA>lenB){
        
        int diff = lenA-lenB;

        for(int i=0; i<diff; i++){
            tempA = tempA->next;
        }
    }

    else if(lenA<lenB){
        
        int diff = lenB-lenA;

        for(int i=0; i<diff; i++){
            tempB = tempB->next;
        }
    }

    while(tempA != tempB){
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return tempA;


}



int main() {

    // Common part
    Node* c1 = new Node(8);
    Node* c2 = new Node(10);

    c1->next = c2;

    // List A: 3 → 6 → 8 → 10
    Node* a1 = new Node(3);
    Node* a2 = new Node(6);

    a1->next = a2;
    a2->next = c1;

    // List B: 4 → 8 → 10
    Node* b1 = new Node(4);

    b1->next = c1;

    Node* headA = a1;
    Node* headB = b1;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    Node* intersection1 = getIntersectionNode1(headA, headB);
    Node* intersection2 = getIntersectionNode2(headA, headB);

    if(intersection1 != NULL)   cout << "Intersection Node: " << intersection1->val << endl;
    if(intersection2 != NULL)   cout << "Intersection Node: " << intersection2->val << endl;
    else                        cout << "No Intersection" << endl;

    return 0;
}
