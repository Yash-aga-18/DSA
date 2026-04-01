#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1038   Modify given BST to Greater Sum tree

// you have given a BST, pick each node and replace it with the sum of all the nodes 
// having greater than the value from it + it's own value


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

Node* insert(Node* root, int val) {

    if(root == NULL) return new Node(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}



// -------- Reverse Inorder --------
void inorder(Node* root, int &sum) {

    if(root == NULL) return;

    inorder(root->right, sum);

    sum += root->val;
    root->val = sum;

    inorder(root->left, sum);
}


Node* bstToGst(Node* root) {

    int sum = 0;   // inside function (NOT in main)
    inorder(root, sum);

    return root;
}




void in_print(Node* root) {

    if(root == NULL) return;

    in_print(root->left);
    cout<<root->val<<" ";
    in_print(root->right);

}

int main() {

    Node* root = NULL;

    vector<int> values = {4, 1, 6, 0, 2, 5, 7};

    for(int x : values) {
        root = insert(root, x);
    }

    cout << "before: ";
    in_print(root);
    cout << endl;

    root = bstToGst(root);

    cout << "after: ";
    in_print(root);
    cout << endl;


    return 0;
}