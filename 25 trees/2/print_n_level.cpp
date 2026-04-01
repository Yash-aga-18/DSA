#include <bits/stdc++.h>
using namespace std;

// print the n-th level
// 0 based indexing

class Node {
public: 
    
    int val;
    Node *left;
    Node *right;

    Node(int val) {
        this->val   = val;
        this->left  = NULL;
        this->right = NULL;
    }
};


void display(Node* root, int level, int curr) {

    if (root == NULL) return;

    // If current level matches target level → print
    if (curr == level) {
        cout << root->val << " ";
        return;
    }

    // Go deeper with incremented level
    display(root->left,  level, curr + 1);
    display(root->right, level, curr + 1);
}


int main()
{
    Node* a = new Node(1);    
    Node* b = new Node(2);    
    Node* c = new Node(3);    
    Node* d = new Node(4);    
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);
    
    a->left  = b;
    a->right = c;
    b->left  = d;
    b->right = e;
    c->left  = f;
    c->right = g;
    d->left  = h;

    Node* head = a;
    int level = 2;   

    display(head, level, 0);

    return 0;
}