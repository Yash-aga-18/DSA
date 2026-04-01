#include <bits/stdc++.h>
using namespace std;

// leetcode Q->543   Diameter of Binary tree

// The diameter of a binary tree is the length of the longest path 
// between any two nodes in a tree. 
// This path may or may not pass through the root.


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


// ---------------- HEIGHT FUNCTION ----------------
int height(TreeNode* root, int &diameter) {
    
    if (root == NULL) return 0;

    // Recursively get height of left and right subtree
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    // Update diameter:
    // longest path passing through current node
    diameter = max(diameter, left + right);

    // Return height of current node
    return 1 + max(left, right);
}



int main()
{

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int diameter = 0;

    height(root, diameter);

    cout << "Diameter of Binary Tree: " << diameter << endl;

    return 0;
}