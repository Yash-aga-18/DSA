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

// ---------------- inORDER FUNCTION ----------------
void inorder(Node* root, vector<int>& ans) {

    stack<Node*> st;
    Node* curr = root;

    while (curr != NULL || !st.empty()) {

        // go left
        if (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        
        else {
            Node* node = st.top();
            st.pop();

            ans.push_back(node->val);   // visit

            curr = node->right;         // go right
        }
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

    inorder(a, ans);

    // print result
    cout << "inorder Traversal: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}