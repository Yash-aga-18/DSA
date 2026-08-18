#include <bits/stdc++.h>
using namespace std;

// ---------------- NODE ----------------
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


// ---------------- LEFT VIEW ----------------

vector<int> leftView(Node *root) {

    vector<int> ans;

    if (root == NULL)   return ans;


    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            // Store the first node of every level.
            // Since BFS visits nodes from left to right,
            // the first node encountered is the left view.
            if (i == 0) ans.push_back(node->val);

            // Left child
            if (node->left)         q.push(node->left);

            // Right child
            if (node->right)        q.push(node->right);
            
        }
    }

    return ans;
}


// ---------------- RIGHT VIEW ----------------

vector<int> rightView(Node *root) {

    vector<int> ans;

    if (root == NULL)   return ans;


    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            // Store the last node of every level.
            // Since BFS visits nodes from left to right,
            // the last node encountered is the right view.
            if (i == size - 1)      ans.push_back(node->val);

            // Left child
            if (node->left)         q.push(node->left);

            // Right child
            if (node->right)        q.push(node->right);
            
        }
    }

    return ans;
}


int main() {

    /*
                1
               / \
              2   3
             / \   \
            4   5   7
                 \  /
                  6 8
    */

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

    e->right = f;

    c->right = g;

    g->left  = h;


    vector<int> left = leftView(a);
    vector<int> right = rightView(a);


    cout << "Left View:  ";
    for (int x : left) cout << x << " ";
    cout << endl;

    cout << "Right View: ";
    for (int x : right) cout << x << " ";
    cout << endl;

    return 0;
}