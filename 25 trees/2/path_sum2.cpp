#include <bits/stdc++.h>
using namespace std;

// leetcode Q->113 Path Sum 2
// return all the path from root to leaf having equal to targetSum

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

// ---------------- DFS FUNCTION ----------------
void DFS(Node* root, int targetSum, int curr_sum, vector<int>& path, vector<vector<int>>& ans) {

    if (root == NULL) return;

    // take node
    path.push_back(root->val);
    curr_sum += root->val;

    // leaf check
    if (root->left == NULL && root->right == NULL) {
        if (curr_sum == targetSum) {
            ans.push_back(path);
        }
        path.pop_back();   // 🔥 important
        return;
    }

    // explore
    DFS(root->left, targetSum, curr_sum, path, ans);
    DFS(root->right, targetSum, curr_sum, path, ans);

    // backtrack
    path.pop_back();   // 🔥 MUST
}

// ---------------- PATH SUM FUNCTION ----------------
vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;

    DFS(root, targetSum, 0, path, ans);

    return ans;
}

// ---------------- MAIN ----------------
int main() {

    /*
            5
           / \
          4   8
         /   / \
        11  13  4
       / \      / \
      7   2    5   1
    */

    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(8);
    Node* d = new Node(11);
    Node* e = new Node(13);
    Node* f = new Node(4);
    Node* g = new Node(7);
    Node* h = new Node(2);
    Node* i = new Node(5);
    Node* j = new Node(1);

    a->left = b;
    a->right = c;
    b->left = d;
    d->left = g;
    d->right = h;
    c->left = e;
    c->right = f;
    f->left = i;
    f->right = j;

    int targetSum = 22;

    vector<vector<int>> ans = pathSum(a, targetSum);

    cout << "Paths with sum " << targetSum << ":\n";

    for (auto &vec : ans) {
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}