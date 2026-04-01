#include <bits/stdc++.h>
using namespace std;

// leetcode Q->98       Validate that the given tree is BST or not

// method-1        root>max(LST)  &&  root<min(RST)
// method-2        inorder of BST is always sorted (vector)
// method-3        inorder check using prev pointer (optimized)
// method-4        Morris traversal (best)

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int val) {

    if(root == NULL) return new Node(val);

    if(val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}


// ================= METHOD 2 =================
// ---------------- INORDER ----------------
void inorder(Node* root, vector<int>& ans) {

    if(root == NULL) return;

    inorder(root->left, ans);
    ans.push_back(root->val);
    inorder(root->right, ans);
}

// ---------------- CHECK BST (Vector) ----------------
bool isValidBST_Vector(Node* root) {

    vector<int> ans;

    inorder(root, ans);

    for(int i = 0; i < ans.size() - 1; i++) {
        if(ans[i] >= ans[i+1]) return false;
    }

    return true;
}



// ================= METHOD 3 =================
// -------- INORDER WITH PREV POINTER --------

void inorderCheck(Node* root, Node* &prev, bool &flag) {

    if(root == NULL || flag == false) return;

    inorderCheck(root->left, prev, flag);

    if(prev != NULL) {
        if(root->val <= prev->val) {
            flag = false;
            return;
        }
    }

    prev = root;

    inorderCheck(root->right, prev, flag);
}

// -------- CHECK BST (Optimized) --------
bool isValidBST_Optimized(Node* root) {

    Node* prev = NULL;
    bool flag = true;

    inorderCheck(root, prev, flag);

    return flag;
}



int main() {

    Node* root = NULL;

    // Build BST
    vector<int> values = {10, 5, 15, 3, 7, 12, 20};

    for(int x : values) {
        root = insert(root, x);
    }

    // Method 2
    if(isValidBST_Vector(root))
        cout << "Valid BST (Vector Method)" << endl;
    else
        cout << "Not a BST (Vector Method)" << endl;

    // Method 3
    if(isValidBST_Optimized(root))
        cout << "Valid BST (Optimized Method)" << endl;
    else
        cout << "Not a BST (Optimized Method)" << endl;

    return 0;
}