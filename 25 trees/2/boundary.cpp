#include <bits/stdc++.h>
using namespace std;

// Print all the nodes at the boundary
//  Hint:
//      1) print all the left using preorder
//      2) print all the leaves
//      3) print all the right side but in reverse order


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


// ---------------- LEFT BOUNDARY ----------------      except all leaf nodes
void leftBoundary(Node* root) {
    if (root == NULL) return;

    if (root->left != NULL) {
        cout << root->val << " ";
        leftBoundary(root->left);
    }

    else if (root->right != NULL) {
        cout << root->val << " ";
        leftBoundary(root->right);
    }
}

// ---------------- LEAF NODES ----------------
void bottomBoundary(Node* root) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        cout << root->val << " ";
        return;
    }

    bottomBoundary(root->left);
    bottomBoundary(root->right);
}

// ---------------- RIGHT BOUNDARY ----------------     except all leaf nodes
void rightBoundary(Node* root) {
    if (root == NULL) return;

    if (root->right != NULL) {
        rightBoundary(root->right);
        cout << root->val << " ";   // 🔥 print AFTER recursion
    }
    else if (root->left != NULL) {
        rightBoundary(root->left);
        cout << root->val << " ";   // 🔥 print AFTER recursion
    }
}



void boundaryTraversal(Node* root) {
    if (root == NULL) return;

    cout << root->val << " ";      // root

    leftBoundary(root->left);      // left boundary
    bottomBoundary(root);          // leaf nodes
    rightBoundary(root->right);    // right boundary
}


// ---------------- MAIN ----------------
int main() {

    /*
            1
          /   \
         7     9
        / \     \
       2   6     0
      /         / \
     8         13  7
    */

    Node* a = new Node(1);
    Node* b = new Node(7);
    Node* c = new Node(9);
    Node* d = new Node(2);
    Node* e = new Node(6);
    Node* f = new Node(0);
    Node* g = new Node(8);
    Node* h = new Node(13);
    Node* i = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    d->left = g;
    c->right = f;
    f->left = h;
    f->right = i;

    Node* root = a;

    boundaryTraversal(root);

    return 0;
}