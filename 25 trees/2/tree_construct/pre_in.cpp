#include <bits/stdc++.h>
using namespace std;

// leetcode Q->105 Construct tree from preorder and inorder


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
Node* build(vector<int>& pre, int preLow, int preHigh, vector<int>& in, int inLow, int inHigh) {

    // Base case: no elements
    if (preLow > preHigh)   return NULL;
    

    // First element in preorder is always root
    Node* root = new Node(pre[preLow]);

    // If only one node, return it
    if (preLow == preHigh)  return root;
    

    // Find root index in inorder
    int i = inLow;
    while (i <= inHigh) {
        
        if (in[i] == pre[preLow])   break;
        i++;
    }


    // Number of nodes in left subtree
    int leftCount = i - inLow;

    // ---------------- LEFT SUBTREE ----------------
    // preorder range: next elements equal to leftCount
    // inorder range: inLow to i-1
    root->left = build(pre, preLow + 1, preLow + leftCount, in, inLow, i - 1);



    // ---------------- RIGHT SUBTREE ----------------
    // preorder range: remaining elements
    // inorder range: i+1 to inHigh
    root->right = build(pre, preLow + leftCount + 1, preHigh, in, i + 1, inHigh);


    return root;
}



// ---------------- BUILD TREE WRAPPER ----------------
Node* buildTree(vector<int>& pre, vector<int>& in) {

    int n = pre.size();

    // Edge case
    if (n == 0) return NULL;

    return build(pre, 0, n - 1, in, 0, n - 1);
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

    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in  = {9, 3, 15, 20, 7};

    Node* root = buildTree(pre, in);

    cout << "BFS (Level Order): "<< endl;
    bfsPrint(root);

    cout << endl;

    return 0;
}