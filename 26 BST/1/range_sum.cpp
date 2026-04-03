#include <bits/stdc++.h>
using namespace std;

// leetcode Q->938  find the sum of values given in low and high range


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


void helper(TreeNode* root, int low, int high, int &sum) {

    if (root == NULL)       return;

    // skip left subtree
    if (root->val < low)    return helper(root->right, low, high, sum);

    // skip right subtree
    if (root->val > high)   return helper(root->left,  low, high, sum);

    // node is in range
    else {
        sum += root->val;
        helper(root->left,  low, high, sum);
        helper(root->right, low, high, sum);
    }

}


int rangeSumBST(TreeNode* root, int low, int high) {
    
    int sum = 0;

    helper(root, low, high, sum);

    return sum;
}



TreeNode* buildTree() {

    /*
            10
           /  \
          5    15
         / \     \
        3   7     18
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);

    root->right->right = new TreeNode(18);

    return root;
}

int main() {

    TreeNode* root = buildTree();

    int low = 7;
    int high = 15;

    int ans = rangeSumBST(root, low, high);

    cout << "Range Sum: " << ans << endl;

    return 0;
}