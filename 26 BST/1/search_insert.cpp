#include <iostream>
using namespace std;

// leetcode Q->700  Search an elemnt in  BST
// leetcode Q->701  Insert an elemnt in  BST


// Tree Node structure
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


// Function to search in BST
TreeNode* searchBST(TreeNode* root, int target) {

    if(root == NULL) return NULL;
    if(root->val == target) return root;

    if(target < root->val)      return searchBST(root->left, target);
    else                        return searchBST(root->right, target);

}


// function to insert into BST
TreeNode* insertIntoBST(TreeNode* root, int target) {

    if(root == NULL)        return new TreeNode(target);

    if(target < root->val)      root->left  = insertIntoBST(root->left, target);
    else                        root->right = insertIntoBST(root->right, target);
    
    return root;
}



int main() {

    TreeNode* root = NULL;

    // Creating BST
    root = insertIntoBST(root, 10);
    insertIntoBST(root, 5);
    insertIntoBST(root, 15);
    insertIntoBST(root, 12);

    int target = 12;

    TreeNode* result = searchBST(root, target);

    if(result != NULL) {
        cout << "Found: " << result->val << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}