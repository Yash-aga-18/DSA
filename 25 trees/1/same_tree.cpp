#include <bits/stdc++.h>
using namespace std;

// leetcode Q->100  Same tree
// return true if the given 2 trees are same



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


// ---------------- FUNCTION ----------------
bool isSameTree(TreeNode* p, TreeNode* q) {

    // Case 1: both NULL → same
    if (p == NULL && q == NULL)     return true;
    

    // Case 2: one NULL, one not → not same
    if (p == NULL || q == NULL)     return false;
    

    // Case 3: values different → not same
    if (p->val != q->val)           return false;
    

    // Case 4: check left and right subtree
    return  ( isSameTree(p->left, q->left) &&  isSameTree(p->right, q->right) );
}


// ---------------- MAIN ----------------
int main()
{
    /*
        Tree 1:        Tree 2:

            1              1
           / \            / \
          2   3          2   3

        Output: Same Tree (true)
    */

    // Tree 1
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = isSameTree(p, q);

    if (result) cout << "Trees are Same" << endl;
    else        cout << "Trees are NOT Same" << endl;
    

    return 0;
}