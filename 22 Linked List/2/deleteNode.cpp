#include <bits/stdc++.h>
using namespace std;

// leetcode Q->237      Delete a node from LL without using Head

class Node{
 public:

    int val;        // it stores the current value
    Node *next;     // it stores the address of next elemnt

    Node(int val){
        this->val = val;
        this->next = NULL;
    }

};


// Helper function to print list
void printList(Node* head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteNode(Node* target) {
        
    target->val = target->next->val;

    Node *toDelete = target->next;
    
    target->next = target->next->next; 
    delete toDelete;

}



int main()
{
    
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    Node* head = a;          // define head
    
    cout << "Original List: ";
    printList(head);
    
    deleteNode(b);          // node to delete (delete 20)


    cout << "After Deletion: ";
    printList(head);



 return 0;

}

/* 
In a singly linked list, deleting a node normally requires access to its previous node.
But in this problem, we are only given the pointer to the node itself, not the head.

Since we can't move backward in a singly linked list and we don’t have access to the previous node, 
so, we can't delete the current node directly.

However, since the given node is guaranteed not to be the last node, 
we can copy the value of the next node into the current node and then delete the next node instead.
This effectively removes the given value from the list.

*/