#include <bits/stdc++.h>
using namespace std;

// leetcode Q->112      Path Sum 1  
// return true/false if any root to leaf sum is equals to target


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
bool DFS(Node* root, int targetSum, int curr_sum) {

    if (root == NULL) return false;

    // include current node
    curr_sum += root->val;

    // leaf node
    if (root->left == NULL && root->right == NULL) {
        return curr_sum == targetSum;
    }

    // explore left OR right
    return DFS(root->left, targetSum, curr_sum) || DFS(root->right, targetSum, curr_sum);
}

// ---------------- MAIN ----------------
int main()
{
    /*
            5
           / \
          4   8
         /   / \
       11   13  4
       / \        \
      7   2        1
    */

    Node* a = new Node(5);
    Node* b = new Node(4);
    Node* c = new Node(8);
    Node* d = new Node(11);
    Node* e = new Node(13);
    Node* f = new Node(4);
    Node* g = new Node(7);
    Node* h = new Node(2);
    Node* i = new Node(1);

    a->left = b;
    a->right = c;

    b->left = d;

    d->left = g;
    d->right = h;

    c->left = e;
    c->right = f;

    f->right = i;

    Node* root = a;

    int targetSum = 22;

    if (DFS(root, targetSum, 0)) cout << "Path exists" << endl;
    else                         cout << "Path does NOT exist" << endl;
    

    return 0;
}