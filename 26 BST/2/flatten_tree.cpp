#include <bits/stdc++.h>
using namespace std;

// leetcode Q->114  Flatten a Tree To LL


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


// =====================================================
// METHOD 1: PREORDER + VECTOR      (O(n) space)
// =====================================================
void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
    if(root == NULL) return;

    nodes.push_back(root);
    preorder(root->left, nodes);
    preorder(root->right, nodes);
}

void flatten_method1(TreeNode* root) {
    
    if(root == NULL) return;

    vector<TreeNode*> nodes;

    preorder(root, nodes);

    for(int i = 0; i < nodes.size() - 1; i++) {
        nodes[i]->left = NULL;
        nodes[i]->right = nodes[i + 1];
    }
}



// =====================================================
// METHOD 2: RECURSION (Reverse Preorder)   (O(n) space)
// =====================================================

// void flatten_method2(TreeNode* root) {
    
//     if(root == NULL) return;

//     TreeNode* l = root->left;
//     TreeNode* r = root->right;

//     root->left = NULL;
//     root->right = NULL;

//     flatten_method2(l);
//     flatten_method2(r);

//     // attach left subtree to right
//     root->right = l;

//     // go to end of new right subtree
//     TreeNode* temp = root;
//     while(temp->right != NULL) {
//         temp = temp->right;
//     }

//     // attach original right subtree
//     temp->right = r;
// }


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Reverse preorder + head insertion = flatten

TreeNode* prevNode = NULL;   // will store previously processed node

void flatten_method2(TreeNode* root) {
    
    if(root == NULL) return;   // base case

    // process right subtree first (reverse preorder)
    flatten_method2(root->right);

    // then process left subtree
    flatten_method2(root->left);

    // attach already processed list to current node
    root->right = prevNode;    // link current node to previous node
    root->left  = NULL;         // make left NULL (as required)

    // update prevNode to current node
    prevNode = root;
}



// =====================================================
// METHOD 3: MORRIS (O(1) space) 🔥 BEST
// =====================================================
void flatten_method3(TreeNode* root) {
    
    TreeNode* curr = root;

    while(curr != NULL) {

        if(curr->left != NULL) {    // find predecessor
            TreeNode* pred = curr->left;

            while(pred->right != NULL)  pred = pred->right;
        
            // connect right subtree
            pred->right = curr->right;

            // move left subtree
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}




TreeNode* buildTree() {

    /*
            1
           / \
          2   5
         / \   \
        3   4   6
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(6);

    return root;
}

void printList(TreeNode* root) {
    while(root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {

    // choose which method to test

    TreeNode* root1 = buildTree();
    flatten_method1(root1);
    cout << "Method 1 (Vector): ";
    printList(root1);


    TreeNode* root2 = buildTree();
    flatten_method2(root2);
    cout << "Method 2 (Recursion): ";
    printList(root2);


    TreeNode* root3 = buildTree();
    flatten_method3(root3);
    cout << "Method 3 (Morris): ";
    printList(root3);

    return 0;
}