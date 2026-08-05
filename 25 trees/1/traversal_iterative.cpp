#include <bits/stdc++.h>
using namespace std;

// LeetCode Q->144, 94, 145
// Iterative Preorder, Inorder and Postorder Traversal (ITERATIVELY)

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

vector<int> preorder(Node* root, vector<int>& ans) {

    if (root == NULL)   return ans;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {

        Node* node = st.top();
        st.pop();

        ans.push_back(node->val);

        // push right first, then left
        if (node->right != NULL) st.push(node->right);
        if (node->left  != NULL) st.push(node->left);
    }

    return ans;
}


// ---------------- INORDER ----------------    Left -> Root -> Right

vector<int> inorder(Node* root, vector<int>& ans) {

    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {

        // go left
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        ans.push_back(curr->val);   // visit

        curr = curr->right;         // go right
    }

    return ans;
}


// ---------------- POSTORDER ----------------    Left -> Right -> Root

vector<int> postorder(Node* root, vector<int>& ans) {

    if (root == NULL)   return ans;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()) {

        Node* node = st.top();
        st.pop();

        ans.push_back(node->val);

        // push left first, then right
        if (node->left  != NULL) st.push(node->left);
        if (node->right != NULL) st.push(node->right);
    }

    reverse(ans.begin(), ans.end());

    return ans;
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