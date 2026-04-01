#include <bits/stdc++.h>
using namespace std;

// leetcode Q->889 Construct tree from preorder and postorder


// ---------------- TREE NODE ----------------
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


// ---------------- BUILD FUNCTION ----------------
Node* build(vector<int>& pre, int preLow, int preHigh, vector<int>& post, int postLow, int postHigh) {

    // Base case
    if (preLow > preHigh) return NULL;

    // Root from preorder
    Node* root = new Node(pre[preLow]);

    // If single node
    if (preLow == preHigh) return root;

    // Left subtree root (VERY IMPORTANT)
    int leftRoot = pre[preLow + 1];

    // Find leftRoot in postorder
    int i = postLow;
    while (i <= postHigh) {
        if (post[i] == leftRoot) break;
        i++;
    }

    // Size of left subtree
    int leftCount = i - postLow + 1;

    // ---------------- LEFT SUBTREE ----------------
    root->left = build(pre, preLow +1 , preLow + leftCount, post, postLow, i);

    // ---------------- RIGHT SUBTREE ----------------
    root->right = build(pre, preLow + leftCount+ 1, preHigh, post, i + 1, postHigh - 1);

    return root;
}

// ---------------- BUILD TREE WRAPPER ----------------
Node* buildTree(vector<int>& pre, vector<int>& post) {

    int n = pre.size();

    // Edge case
    if (n == 0) return NULL;

    return build(pre, 0, n - 1, post, 0, n - 1);
}



// ---------------- BFS ORDER PRINT (FOR VERIFICATION) ----------------
void bfsPrint(Node* root) {

    if (root == NULL) {
        cout << "NULL" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        // Check if next level is all NULL → stop (to avoid infinite NULLs)
        bool allNull = true;
        queue<Node*> temp = q;

        while (!temp.empty()) {
            if (temp.front() != NULL) {
                allNull = false;
                break;
            }
            temp.pop();
        }

        if (allNull) break;

        // Process one level
        while (size--) {

            Node* curr = q.front();
            q.pop();

            if (curr == NULL) {
                cout << "NULL ";
                q.push(NULL);
                q.push(NULL);
            }
            else {
                cout << curr->val << " ";
                q.push(curr->left);
                q.push(curr->right);
            }
        }

        cout << endl; // next level
    }
}

// ---------------- MAIN FUNCTION ----------------
int main() {

    vector<int> pre  = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};

    Node* root = buildTree(pre, post);

    cout << "BFS (Level Order): "<< endl;
    bfsPrint(root);

    cout << endl;

    return 0;
}