#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1382   Balance a Unbalanced BST

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};


// 🔹 Step 1: inorder → store sorted values
void inorder(TreeNode* root, vector<int> &arr) {

    if (root == NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->val);
    inorder(root->right, arr);
}


// 🔹 Step 2: build balanced BST
TreeNode* build(vector<int> &arr, int low, int high) {

    if (low > high) return NULL;

    int mid = (low + high) / 2;

    TreeNode* root = new TreeNode(arr[mid]);

    root->left  = build(arr, low, mid - 1);
    root->right = build(arr, mid + 1, high);

    return root;
}


// 🔹 Main function to balance BST
TreeNode* balanceBST(TreeNode* root) {

    vector<int> arr;

    inorder(root, arr);   // get sorted values

    return build(arr, 0, arr.size() - 1);
}



void printInorder(TreeNode* root) {
    if (root == NULL) return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {

    // Example: unbalanced BST
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Original BST (Inorder): ";
    printInorder(root);
    cout << endl;

    TreeNode* newRoot = balanceBST(root);

    cout << "Balanced BST (Inorder): ";
    printInorder(newRoot);
    cout << endl;

    return 0;
}