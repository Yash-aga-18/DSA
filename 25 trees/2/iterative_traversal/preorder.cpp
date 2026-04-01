#include <bits/stdc++.h>
using namespace std;

// ---------------- TREE NODE ----------------
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// ---------------- PREORDER FUNCTION ----------------
void preorder(Node* root, vector<int>& ans) {

    if (root == NULL) return;

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
}

// ---------------- MAIN ----------------
int main() {

    // creating tree
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

    vector<int> ans;

    preorder(a, ans);

    // print result
    cout << "Preorder Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}