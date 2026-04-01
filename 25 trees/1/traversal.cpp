#include <bits/stdc++.h>
using namespace std;

// leetcode Q->144 , 94, 145
// return the vector of pre,in,post traversal nodes


struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


// ---------------- PREORDER ----------------    Root -> Left -> Right

void preorder(Node* root, vector<int>& ans) {
    
    if (root == NULL)   return;
    
    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}


// ---------------- INORDER ----------------    Left -> Root -> Right
void inorder(Node* root, vector<int>& ans) {
    
    if (root == NULL)   return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}


// ---------------- POSTORDER ----------------  Left -> Right -> Root
void postorder(Node* root, vector<int>& ans) {
    
    if (root == NULL)   return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}


int main() {


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

    Node* root = a;


    vector<int> pre, in, post;

    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);


    // Print Preorder
    cout << "Preorder: ";
    for (int x : pre)   cout << x << " ";
    cout << endl;


    // Print Inorder
    cout << "Inorder: ";
    for (int x : in)    cout << x << " ";
    cout << endl;



    // Print Postorder
    cout << "Postorder: ";
    for (int x : post)  cout << x << " ";
    cout << endl;


    return 0;
}