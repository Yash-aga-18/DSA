#include <bits/stdc++.h>
using namespace std;

// leetcode Q->148      Sort the given LL


class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* tempA = list1;
    ListNode* tempB = list2;

    // Dummy node
    ListNode* c = new ListNode(-1);
    ListNode* tempC = c;

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


ListNode* sortList(ListNode* head) {

    // Base Case
    if(head == NULL || head->next == NULL)      return head;

    // Find middle (LEFT middle for EVEN)
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split list into two halves
    ListNode* head2 = slow->next;
    slow->next = NULL;

    // Recursively sort both halves
    ListNode* left  = sortList(head);
    ListNode* right = sortList(head2);

    // Merge sorted halves
    return mergeTwoLists(left, right);

    
}

// Print List
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // Create list: 4 → 2 → 1 → 3
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(1);
    ListNode* a4 = new ListNode(3);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;

    cout << "Original List: ";
    printList(a1);

    ListNode* sorted = sortList(a1);

    cout << "Sorted List: ";
    printList(sorted);

    return 0;
}
