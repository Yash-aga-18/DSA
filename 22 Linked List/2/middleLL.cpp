#include <bits/stdc++.h>
using namespace std;

// leetcode Q->876 return Middle of LL
// in case of EVEN return the second one middle


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to find middle node using 2 pass method
Node* middleNode2(Node* head) {      

    int len = 0;
    Node* temp = head;

    while(temp != NULL){
        len++;
        temp = temp->next;
    }

    int midIdx = len / 2;

    Node* mid = head;
    for(int i = 0; i < midIdx; i++){
        mid = mid->next;
    }
    return mid;

}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Function to find middle node using 1 pass method (slow and fast pointers)
Node* middleNode1(Node* head) {      

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}



// Helper function to print list
void printList(Node* head) {
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

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

    Node* mid2 = middleNode2(head);
    cout << "Middle Node: " << mid2->val << endl;
    
    Node* mid1 = middleNode1(head);
    cout << "Middle Node: " << mid1->val << endl;


 return 0;

}
