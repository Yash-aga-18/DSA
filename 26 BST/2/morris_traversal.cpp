#include <bits/stdc++.h>
using namespace std;

/*
Rules Reminder (very short)
    If left == NULL → visit + go right

    Else:
    Find predecessor
    If no thread →     create + go left
    If thread exists → remove + visit + go right
*/


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

void morrisInorder(TreeNode* root, vector<int>& ans) {
    
    TreeNode* curr = root;

    while(curr != NULL) {

        // case 1: no left subtree
        if(curr->left == NULL) {
            ans.push_back( curr->val );   // visit node
            curr = curr->right;        // move right
        }

        else {      // find inorder predecessor (rightmost of left subtree)
            
            TreeNode* pred = curr->left;

            while(pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            // case 2: first time visiting this node
            if(pred->right == NULL) {
                pred->right = curr;    // create thread (link back)
                curr = curr->left;     // move left
            }

            // case 3: thread already exists → remove it
            else {

                pred->right = NULL;    // restore tree

                ans.push_back( curr->val );  // visit node
                curr = curr->right;        // move right
            }
        }


    }
}


int main() {

    /*
                10
               /  \
              5    15
             / \     \
            2   7     20
             \        /
              3      17

    Inorder should be:
    2 3 5 7 10 15 17 20
    */

    TreeNode* root = new TreeNode(10);

    root->left = new TreeNode(5);
    root->right = new TreeNode(15);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);

    root->left->left->right = new TreeNode(3);

    root->right->right = new TreeNode(20);
    root->right->right->left = new TreeNode(17);

    vector<int> ans;

    morrisInorder(root, ans);

    // print result
    cout << "Inorder Traversal: ";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

/*
==================== MORRIS TRAVERSAL NOTES ====================

1. What is Morris Traversal?
---------------------------------------------------------------
- A tree traversal technique that uses NO recursion and NO stack.
- Achieves O(1) space complexity.
- Uses temporary modification of tree (called "threading").

---------------------------------------------------------------
2. Key Idea
---------------------------------------------------------------
For each node:

CASE 1: If left child is NULL
    → Visit the node
    → Move to right child

CASE 2: If left child exists
    → Find inorder predecessor (rightmost node in left subtree)

    SUBCASE A: predecessor->right == NULL
        → Create temporary link (thread)
        → predecessor->right = current node
        → Move to left child

    SUBCASE B: predecessor->right == current
        → Thread already exists (means left subtree is done)
        → Remove thread (restore tree)
        → Visit current node
        → Move to right child

---------------------------------------------------------------
3. Why it works?
---------------------------------------------------------------
- Instead of using stack, we create a temporary path back to parent.
- This allows us to return to node after finishing left subtree.

---------------------------------------------------------------
4. Time & Space Complexity
---------------------------------------------------------------
Time: O(n)      Each node is visited at most 2 times
Space: O(1)     No recursion or stack used

---------------------------------------------------------------
5. Important Points
---------------------------------------------------------------
- Always restore the tree (remove threads)
- Check: pred->right != curr (to avoid infinite loop)
- Traversal order depends on WHEN you "visit" node

---------------------------------------------------------------
6. Traversal Variants
---------------------------------------------------------------
Inorder  → Left, Root, Right
Preorder → Root, Left, Right (visit before going left)
Postorder → Complex (reverse path technique)

===============================================================
*/



/*
for preoder just change 1 line-->

// first time → create thread + VISIT
    if(pred->right == NULL) {
        ans.push_back(curr->val);   // 🔥 preorder visit here
        pred->right = curr;
        curr = curr->left;
    }

    // second time → remove thread
    else {
        pred->right = NULL;
        curr = curr->right;
    }



*/