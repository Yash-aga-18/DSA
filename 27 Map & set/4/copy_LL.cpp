#include <bits/stdc++.h>
using namespace std;

// leetcode Q->138   Deep copy a given LL which have both random and NULL ptr

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// ===============================
// APPROACH 1: Using HashMap
// ===============================
Node* copyUsingMap(Node* head)
{
    if(head == NULL) return NULL;

    unordered_map<Node*, Node*> mp;
    Node* curr = head;

    // Step 1: Create copy nodes
    while(curr != NULL)
    {
        mp[curr] = new Node(curr->val);
        curr = curr->next;
    }

    // Step 2: Assign next and random
    curr = head;

    while(curr != NULL)
    {
        mp[curr]->next = mp[curr->next];      // handles NULL automatically
        mp[curr]->random = mp[curr->random];  // handles NULL automatically

        curr = curr->next;
    }

    return mp[head];
}


// ===============================
// APPROACH 2: Optimal (O(1) Space)
// ===============================
Node* copyOptimal(Node* head)
{
    if(head == NULL)    return NULL;

    Node* curr = head;

    // Step 1: Insert copy nodes in between the existing nodes
    while(curr != NULL)
    {
        Node* newNode = new Node(curr->val);

        newNode->next = curr->next;
        curr->next = newNode;

        curr = newNode->next;
    }

    // Step 2: Assign random pointers
    curr = head;

    while(curr != NULL)
    {
        if(curr->random != NULL)    curr->next->random = curr->random->next;


        curr = curr->next->next;
    }

    // Step 3: Separate lists
    Node* dummy = new Node(0);
    Node* copy = dummy;

    curr = head;

    while(curr != NULL)
    {
        copy->next = curr->next;
        copy = copy->next;

        curr->next = curr->next->next;
        curr = curr->next;

    }

    return dummy->next;
}



int main()
{
    // Creating example list:
    // 1 -> 2 -> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // random pointers
    head->random = head->next->next;   // 1 -> 3
    head->next->random = head;         // 2 -> 1
    head->next->next->random = head;   // 3 -> 1

    Node* copy1 = copyUsingMap(head);
    Node* copy2 = copyOptimal(head);

    cout << "Copy using HashMap created.\n";
    cout << "Copy using Optimal approach created.\n";

    return 0;
}