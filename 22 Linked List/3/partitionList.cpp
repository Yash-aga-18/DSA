#include <bits/stdc++.h>
using namespace std;

// Leetcode Q->86  Partition List
// Rearrange list so that all nodes (less than x) come before nodes (greater than or equals to x)


class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Partition function
Node* partitionList(Node* head, int x) {

    Node* temp = head;

    // Dummy nodes
    Node* low  = new Node(-1);
    Node* high = new Node(-1);

    Node* tempLow  = low;
    Node* tempHigh = high;

    while(temp != NULL) {

        Node* nextNode = temp->next;  // save next
        temp->next = NULL;            // break old link

        if(temp->val < x) {
            tempLow->next = temp;
            tempLow = temp;
        }
        else {
            tempHigh->next = temp;
            tempHigh = temp;
        }

        temp = nextNode;
    }

    // Connect both lists
    tempLow->next = high->next;

    return low->next;   // skip dummy
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

    // Create list: 1 → 4 → 3 → 2 → 5 → 2
    Node* n1 = new Node(1);
    Node* n2 = new Node(4);
    Node* n3 = new Node(3);
    Node* n4 = new Node(2);
    Node* n5 = new Node(5);
    Node* n6 = new Node(2);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    cout << "Original List: ";
    printList(n1);

    int x = 3;

    Node* result = partitionList(n1, x);

    cout<<"for x = "<< x<< endl;
    cout << "Partitioned List: ";
    printList(result);

    return 0;
}
