#include <bits/stdc++.h>
using namespace std;

// leetcode Q->437 Path Sum 3
// return count of no. of path having equal to targetSum (not necessary start from root)

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


// count paths starting EXACTLY from this node
int countFromNode(Node* node, long long sum, int target) {
    
    if (node == NULL) return 0;

    sum += node->val;
    int count = 0;

    if (sum == target) count++;
    

    count += countFromNode(node->left,  sum, target);
    count += countFromNode(node->right, sum, target);

    return count;

}



int pathSum(Node* root, int targetSum) {
    
    if (root == NULL) return 0;

    int count = 0;

    // paths starting from current node
    count += countFromNode(root, 0, targetSum);

    // try left and right as new starting points
    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count;
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

    int ans = pathSum(a, targetSum);
    cout << "Number of paths with sum " << targetSum << " = " << ans << endl;

 return 0;

}