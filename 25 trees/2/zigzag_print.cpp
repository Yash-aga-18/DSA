#include <bits/stdc++.h>
using namespace std;

// leetcode Q->103  ZigZag Level Order Traversal
// return all the levels left to right 
// and next with right to left

// ---------------- NODE ----------------
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


// ---------------- HEIGHT ----------------
int levels(Node* root) {
    if (root == NULL) return 0;

    return 1 + max(levels(root->left), levels(root->right));
}


// ---------------- NTH LEVEL ----------------
void nthLevel(Node* root, int curr, int level, vector<int>& v) {

        if (root == NULL)   return;

        if (curr == level) {
            v.push_back(root->val);
            return;
        }

        if(level%2 == 0){       
            nthLevel(root->right, curr + 1, level, v);
            nthLevel(root->left,  curr + 1, level, v);

        }
        else{
            nthLevel(root->left,  curr + 1, level, v);
            nthLevel(root->right, curr + 1, level, v);

        }

    }


// ---------------- LEVEL ORDER ----------------
vector<vector<int>> levelOrder(Node* root) {

    vector<vector<int>> ans;

    int n = levels(root);   // to get the no. of levels

    for (int i = 1; i <= n; i++) {
        vector<int> v;

        nthLevel(root, 1, i, v);

        ans.push_back(v);
    }

    return ans;
}


// ---------------- MAIN ----------------
int main()
{
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */

    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    Node* root = a;

    vector<vector<int>> ans = levelOrder(root);

    cout << "ZigZag Level Order Traversal:" << endl;

    for (auto level : ans) {
        for (int x : level) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}