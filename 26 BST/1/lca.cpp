#include <bits/stdc++.h>
using namespace std;

// leetcode Q->235   Lowest Common Ancestor of a Binary Search Tree
// it can be done same as Binary Tree Soln but in BST we can do it much better way


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


// ---------------- FUNCTION ----------------
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if(root == NULL) return NULL;

    // Both nodes in left subtree
    if(p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Both nodes in right subtree
    if(p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Split point → this is LCA
    return root;
}


int main()
{
    /*
            3
           /  \
          5    1
         / \  / \
        6  2  0  8
          / \
         7   4

    LCA(5, 1) = 3
    LCA(5, 4) = 5
    */

    // Build Tree
    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Nodes p and q
    TreeNode* p = root->left;                 // 5
    TreeNode* q = root->left->right->right;   // 4

    // ---------------- LOGIC ----------------
    TreeNode* lca = lowestCommonAncestor(root, p, q);

    // ---------------- OUTPUT ----------------
    if (lca != NULL) {
        cout << "LCA: " << lca->val << endl;
    }

    return 0;
}