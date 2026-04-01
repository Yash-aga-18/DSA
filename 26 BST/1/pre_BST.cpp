#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1008   Contruct BST from preorder


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



// -------- INSERT INTO BST --------
TreeNode* insertIntoBST(TreeNode* root, int target) {

    if(root == NULL) return new TreeNode(target);

    if(target < root->val)      root->left  = insertIntoBST(root->left, target);
    else                        root->right = insertIntoBST(root->right, target);

    return root;
}

// -------- BUILD BST FROM PREORDER --------
TreeNode* bstFromPreorder(vector<int>& pre) {

    if(pre.size() == 0) return NULL;

    TreeNode* root = new TreeNode(pre[0]);

    for(int i = 1; i < pre.size(); i++) {
        insertIntoBST(root, pre[i]);
    }

    return root;
}






// -------- INORDER PRINT (to verify BST) --------
void inorder(TreeNode* root) {

    if(root == NULL) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    vector<int> pre = {8, 5, 1, 7, 10, 12};

    TreeNode* root = bstFromPreorder(pre);

    cout << "Inorder: ";
    inorder(root);

    return 0;
}