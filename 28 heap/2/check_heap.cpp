#include <bits/stdc++.h>
using namespace std;

// GFG---> Check wheteher the given BT is maxHeap or not 

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};



// count nodes
int countNodes(Node* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// check complete tree
bool isComplete(Node* root, int i, int n) {
    if(root == NULL)    return true;
    if(i >= n)          return false;

    return isComplete(root->left,  2*i + 1, n)  &&
           isComplete(root->right, 2*i + 2, n);
}

// check max heap property
bool isMaxHeap(Node* root) {
    if(root == NULL) return true;

    if(root->left  && root->data < root->left ->data) return false;
    if(root->right && root->data < root->right->data) return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}


bool isHeap(Node* root) {
    int n = countNodes(root);

    return isComplete(root, 0, n) && isMaxHeap(root);
}

int main() {

    /*
            97
          /    \
        46      37
       /  \    /  \
     12    3  7   31
     / \
    6   9
    */

    Node* root = new Node(97);
    root->left = new Node(46);
    root->right = new Node(37);
    root->left->left = new Node(12);
    root->left->right = new Node(3);
    root->right->left = new Node(7);
    root->right->right = new Node(31);
    root->left->left->left = new Node(6);
    root->left->left->right = new Node(9);

    if(isHeap(root))
        cout << "Yes, it is a Max Heap\n";
    else
        cout << "No, it is NOT a Max Heap\n";

    return 0;
}