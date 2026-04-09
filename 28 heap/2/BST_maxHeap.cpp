#include <bits/stdc++.h>
using namespace std;

// GFG--> convert BST --> Max Heap
// such that LST<RST

// only 2 changes-->
// 1) no require to do reverse as we required LST<RST
// 2) Apply post order



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

// Step 1: store inorder (sorted)
void inorder(Node* root, vector<int>& v) {
        if(root == NULL) return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
    
// CHANGE: preorder → postorder
void postorderFill(Node* root, vector<int>& v, int &i) {
    if(root == NULL) return;

    postorderFill(root->left, v, i);
    postorderFill(root->right, v, i);

    root->data = v[i++];   // assign afte r children
}

void convertToMaxHeapUtil(Node* root) {
    vector<int> v;

    inorder(root, v);   // sorted ascending

    int i = 0;
    postorderFill(root, v, i);
}



void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {

    /*
            4
          /   \
         2     6
        / \   / \
       1   3 5   7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMaxHeapUtil(root);

    cout << "Level Order of Min Heap: ";
    levelOrder(root);

    return 0;
}


