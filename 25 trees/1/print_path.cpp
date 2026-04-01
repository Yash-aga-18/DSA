#include <bits/stdc++.h>
using namespace std;

// leetcode Q->257   Binary Tree Paths

// Given the root of a binary tree, return all root-to-leaf pathsin any order.
// Path format: "1->2->5"


// ---------------- TREE NODE ----------------
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


// ---------------- HELPER FUNCTION ----------------
void helper(TreeNode* root, string s, vector<string>& ans) {

    if (root == NULL) return;

    string curr = to_string(root->val);

    // If leaf node → store path
    if (root->left == NULL && root->right == NULL) {
        s += curr;
        ans.push_back(s);
        return;
    }

    // Recurse left and right with updated path
    helper(root->left,  s + curr + "->", ans);
    helper(root->right, s + curr + "->", ans);
}


int main()
{
    /*
            1
           / \
          2   3
           \
            5

        Paths:
        1->2->5
        1->3
    */

    // Build Tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    // ---------------- LOGIC ----------------
    vector<string> ans;

    helper(root, "", ans);

    // ---------------- OUTPUT ----------------
    cout << "All Root-to-Leaf Paths:" << endl;

    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}