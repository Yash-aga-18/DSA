#include <bits/stdc++.h>
using namespace std;

// method-1 
// Do inorder traversal → gives sorted array
// Store elements in vector  and use Binary Search (BS) to find:
// predecessor → just left of key
// successor → just right of key


// method-2   find while traversal (Optimized)  



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



// Find predecessor and successor
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {

    pre = NULL;
    suc = NULL;

    while (root != NULL) {

        if (root->val == key) {

            // predecessor → max in left subtree
            if (root->left != NULL) {
                Node* temp = root->left;

                while (temp->right != NULL) temp = temp->right;
                
                pre = temp;
            }

            // successor → min in right subtree
            if (root->right != NULL) {
                Node* temp = root->right;
               
                while (temp->left != NULL)  temp = temp->left;
                
                suc = temp;
            }

            return;
        }

        else if (key > root->val) {
            pre = root;              // possible predecessor
            root = root->right;
        }

        else {
            suc = root;              // possible successor
            root = root->left;
        }

    }
}



int main() {

    Node* root = NULL;

    // Creating BST
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 40);

    int key = 15;

    Node* pre = NULL;
    Node* suc = NULL;

    findPreSuc(root, pre, suc, key);


    cout << "Key: " << key << endl;

    if (pre != NULL)    cout << "Predecessor: " << pre->val << endl;
    else                cout << "Predecessor: Not found" << endl;

    if (suc != NULL)    cout << "Successor: " << suc->val << endl;
    else                cout << "Successor: Not found" << endl;

    return 0;
}