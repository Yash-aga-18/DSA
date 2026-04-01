#include <bits/stdc++.h>
using namespace std;

// leetcode Q->725  Split Linked List into K Parts

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to split list into k parts
vector<Node*> splitListToParts(Node* head, int k) {

    vector<Node*> ans;
    Node* temp = head;

    int size = 0;

    // Count size
    while(temp != NULL){
        temp = temp->next;
        size++;
    }

    int sizeOfNode = size / k;
    int rem = size % k;

    temp = head;

    for(int i = 0; i < k; i++){

        Node* c = temp;   // head of current part
        int currentSize = sizeOfNode;

        if(rem > 0){
            currentSize = currentSize + 1;
            rem--;
        }

        // Move to last node of current part
        for(int j = 1; j < currentSize && temp != NULL; j++){
            temp = temp->next;
        }

        if(temp != NULL){
            Node* tempC = temp->next;
            temp->next = NULL;   // break list
            temp = tempC;
        }

        ans.push_back(c);
    }

    return ans;
}

// Helper function to print parts
void printParts(vector<Node*> &ans) {

    for(int i = 0; i < ans.size(); i++) {

        Node* temp = ans[i];

        cout << "[";
        while(temp != NULL) {
            cout << temp->val;
            if(temp->next != NULL) cout << ",";
            temp = temp->next;
        }
        cout << "]";
        cout << endl;
    }
}

int main() {

    // Create Linked List:
    // 10 → 20 → 30 → 40 → 50 → 60 → 70

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);
    Node* e = new Node(50);
    Node* f = new Node(60);
    Node* g = new Node(70);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;

    Node* head = a;

    int k = 3;

    vector<Node*> ans = splitListToParts(head, k);

    printParts(ans);

    return 0;
}