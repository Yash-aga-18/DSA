#include <bits/stdc++.h>
using namespace std;

// leetcode Q->669   Trim a BST on basis of low and high


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


// -------- TRIM FUNCTION --------
TreeNode* trimBST(TreeNode* root, int low, int high) {
    
    if(root == NULL) return NULL;

    if(root->val < low) {
        return trimBST(root->right, low, high);
    }

    if(root->val > high) {
        return trimBST(root->left, low, high);
    }

    root->left  = trimBST(root->left,  low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}



// -------- Insert into BST --------
TreeNode* insertBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    if(val < root->val) {
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// -------- Level Order Print --------
void levelOrder(TreeNode* root) {
    if(root == NULL) {
        cout << "Empty Tree\n";
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                cout << "null ";
                continue;
            }

            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        cout << endl;
    }
}

// -------- MAIN --------
int main() {
    
    vector<int> values = {8,3,10,1,6,14,4,7,13};
    
    TreeNode* root = NULL;

    for(int i = 0; i < values.size(); i++) {
        root = insertBST(root, values[i]);
    }

    cout << "Original Tree:\n";
    levelOrder(root);

    int low = 5;
    int high = 13;

    root = trimBST(root, low, high);

    cout << "\nTrimmed Tree:\n";
    levelOrder(root);

    return 0;
}