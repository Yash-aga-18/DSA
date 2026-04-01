#include <bits/stdc++.h>
using namespace std;

// leetcode Q->236   Lowest Common Ancestor of a Binary Tree

// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes p and q.

// LCA = lowest node that has both p and q as descendants
// (a node can be a descendant of itself)


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
    
    // Base case
    if (root == NULL || root == p || root == q)     return root;
    
    // Search in left and right subtree
    TreeNode* left  = lowestCommonAncestor(root->left,  p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);


    // Meaning:p found in left && q found in right
    // 👉 So current node is LCA
    if(left != NULL && right != NULL)   return root;

    // Case 2: only left side has one of them    Only One Side Found 
    if(left != NULL)    return left;

    // Otherwise return right (could be NULL or actual node)
    return right;
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