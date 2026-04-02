#include <bits/stdc++.h>
using namespace std;

// leetcode Q->450      Delete a Node in BST


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

Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}



// Helper → inorder successor (min in right subtree)
Node* in_succ(Node* root) {

    while (root->left != NULL)  root = root->left;

    return root;
}

// Delete node in BST
Node* deleteNode(Node* root, int key) {

    if (root == NULL) return NULL;

    // Step 1: Find the node
    if (key < root->val)        root->left  = deleteNode(root->left,  key);
    else if (key > root->val)   root->right = deleteNode(root->right, key);
    

    else {  //  Node found

        
        // Case 1: No child
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: One child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children     
        // replace it with inoder pred/succ  and delete it

        Node* succ = in_succ(root->right);
        root->val = succ->val;   // replace value

        root->right = deleteNode(root->right, succ->val);   // now delete successor
    }

    return root;

}




void inorder(Node* root) {
    if (root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Before Deletion: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 50);

    cout << "After Deletion: ";
    inorder(root);
    cout << endl;

    return 0;
}