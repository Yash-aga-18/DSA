#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2385   Amount of Time for Binary Tree to Be Infected



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


//  to build parent map and find target node
TreeNode* buildParent(TreeNode* root, map<TreeNode*, TreeNode*> &parent, int start) {
    
    queue<TreeNode*> q;
    q.push(root);

    TreeNode* target = NULL;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        // find the start node
        if (curr->val == start) {
            target = curr;
        }

        // store parent of left child
        if (curr->left != NULL) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }

        // store parent of right child
        if (curr->right != NULL) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }

    return target;
}


// Function to calculate time to burn tree
int burnTree(TreeNode* target, map<TreeNode*, TreeNode*> &parent) {
    
    queue<TreeNode*> q;
    map<TreeNode*, bool> vis;

    q.push(target);
    vis[target] = true;

    int time = 0;

    while (!q.empty()) {

        int size = q.size();
        bool burned = false;   // track if fire spreads in this level

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();

            // move to left child
            if (curr->left != NULL && vis[curr->left] == false) {
                q.push(curr->left);
                vis[curr->left] = true;
                burned = true;
            }

            // move to right child
            if (curr->right != NULL && vis[curr->right] == false) {
                q.push(curr->right);
                vis[curr->right] = true;
                burned = true;
            }

            // move to parent
            if (parent[curr] != NULL && vis[parent[curr]] == false) {
                q.push(parent[curr]);
                vis[parent[curr]] = true;
                burned = true;
            }
        }

        // increase time only if fire spread
        if (burned == true)     time++;

    }

    return time;
}


int amountOfTime(TreeNode* root, int start) {
    
    map<TreeNode*, TreeNode*> parent;

    // build parent map + get target node
    TreeNode* target = buildParent(root, parent, start);

    // calculate burn time
    return burnTree(target, parent);
}



int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int start = 2;

    cout << amountOfTime(root, start) << endl;

    return 0;
}