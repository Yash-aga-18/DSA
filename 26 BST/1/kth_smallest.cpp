#include <bits/stdc++.h>
using namespace std;

// leetcode Q->230   Return the kth smallest number of BST


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

// -------- INORDER FUNCTION --------
void inorder(TreeNode* root, vector<int>& ans) {
    if(root == NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// -------- KTH SMALLEST --------
int kthSmallest(TreeNode* root, int k) {

    vector<int> ans;
    inorder(root, ans);

    return ans[k - 1];   // 0-based indexing
}



TreeNode* buildTree() {

    /*
            5
           / \
          3   6
         / \
        2   4
       /
      1
    */

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);

    root->left->left->left = new TreeNode(1);

    return root;
}

int main() {

    TreeNode* root = buildTree();

    int k = 3;

    int ans = kthSmallest(root, k);

    cout << "Kth Smallest Element: " << ans << endl;

    return 0;
}