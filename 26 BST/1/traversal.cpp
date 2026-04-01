#include <bits/stdc++.h>
using namespace std;

// return the vector of pre,in,post traversal nodes 
// Note:--> Inorder of BST is always ** sorted **

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


// ---------------- PREORDER ----------------
void preorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;

    ans.push_back(root->val);
    preorder(root->left, ans);
    preorder(root->right, ans);
}

// ---------------- INORDER ----------------
void inorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// ---------------- POSTORDER ----------------
void postorder(Node* root, vector<int>& ans) {
    if (root == NULL) return;

    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->val);
}



// ---------------- INSERT (BST) ----------------
Node* insert(Node* root, int val) {

    if(root == NULL) return new Node(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


int main() {

    Node* root = NULL;

    // Insert values → automatically forms BST
    vector<int> values = {10, 5, 15, 3, 7, 12, 20, 1};

    for(int x : values) {
        root = insert(root, x);
    }

    vector<int> pre, in, post;

    preorder(root, pre);
    inorder(root, in);
    postorder(root, post);


    cout << "Preorder: ";
    for (int x : pre) cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int x : in) cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : post) cout << x << " ";
    cout << endl;

    return 0;
}