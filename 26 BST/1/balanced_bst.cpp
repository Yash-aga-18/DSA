#include <bits/stdc++.h>
using namespace std;

// leetcode Q->108   Construct a BST from given sorted Array


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



// -------- Build BST from sorted array --------
TreeNode* buildBST(vector<int>& arr, int low, int high) {

    if(low > high) return NULL;

    int mid = low + (high - low) / 2;

    TreeNode* root = new TreeNode(arr[mid]);

    root->left  = buildBST(arr, low,     mid - 1);
    root->right = buildBST(arr, mid + 1, high);

    return root;
}


TreeNode* sortedArrayToBST(vector<int>& arr) {
    return buildBST(arr, 0, arr.size() - 1);
}



// -------- Inorder (to verify) --------
void inorder(TreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

    TreeNode* root = sortedArrayToBST(arr);

    // Print inorder → should be sorted
    inorder(root);

    return 0;
}