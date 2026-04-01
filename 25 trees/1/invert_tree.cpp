#include <bits/stdc++.h>
using namespace std;

// leetcode Q->226   Invert Binary Tree

// Given the root of a binary tree, invert the tree, and return its root.
// Inversion means:swap every left and right child in the tree.


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
TreeNode* invertTree(TreeNode* root) {

    // Base case: if tree is empty
    if (root == NULL)   return NULL;
    
    
    // Swap left and right child
    swap(root->left, root->right);

    // Recursively invert left and right subtree
    invertTree(root->left);
    invertTree(root->right);

    return root;
}


// ---------------- MAIN ----------------
int main()
{
    /*
            Original Tree:        Inverted Tree:

                 4                      4
               /   \                  /   \
              2     7      -->       7     2
             / \   / \              / \   / \
            1   3 6   9            9   6 3   1
    */

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    root = invertTree(root);

    // Simple BFS print to verify
    queue<TreeNode*> q;
    q.push(root);

    cout << "Level Order of Inverted Tree: ";

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        cout << curr->val << " ";

        if (curr->left != NULL) {
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    cout << endl;

    return 0;
}