#include <bits/stdc++.h>
using namespace std;

// leetcode Q->23   Merge K sorted lists


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

    Node* dummy = new Node(-1);
    Node* tempC = dummy;

    while (tempA != NULL && tempB != NULL) {

        if (tempA->val <= tempB->val) {
            tempC->next = tempA;
            tempA = tempA->next;
        }
        else {
            tempC->next = tempB;
            tempB = tempB->next;
        }

        tempC = tempC->next;
    }

    // Attach remaining
    if (tempA != NULL)
        tempC->next = tempA;
    else
        tempC->next = tempB;

    return dummy->next;
}

// Merge K sorted linked lists
Node* mergeKLists(vector<Node*>& lists) {

    if (lists.size() == 0)  return NULL;

    while (lists.size() > 1) {

        Node* first = lists[0];
        lists.erase(lists.begin());     // pick the first elemnt head and erase it 

        Node* second = lists[0];
        lists.erase(lists.begin());     // pick the second elemnt head and erase it

        Node* merged = mergeTwoLists(first, second);
        lists.push_back(merged);        // put the merged result at end of list

    }

    return lists[0];
}



// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List 1: 1 → 4 → 5
    Node* a1 = new Node(1);
    Node* a2 = new Node(4);
    Node* a3 = new Node(5);

    a1->next = a2;
    a2->next = a3;

    // List 2: 1 → 3 → 4
    Node* b1 = new Node(1);
    Node* b2 = new Node(3);
    Node* b3 = new Node(4);

    b1->next = b2;
    b2->next = b3;

    // List 3: 2 → 6
    Node* c1 = new Node(2);
    Node* c2 = new Node(6);

    c1->next = c2;

    vector<Node*> lists;
    lists.push_back(a1);
    lists.push_back(b1);
    lists.push_back(c1);

    cout << "Merged K Lists: ";
    Node* result = mergeKLists(lists);
    printList(result);

    return 0;
}
