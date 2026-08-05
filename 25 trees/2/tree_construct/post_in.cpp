#include <bits/stdc++.h>
using namespace std;

// leetcode Q->106 Construct tree from postorder and inorder


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
Node* build(vector<int>& post, int postLow, int postHigh, vector<int>& in, int inLow, int inHigh) {

    // Base case: no elements
    if (postLow > postHigh)   return NULL;
    

    // Last element in postorder is always root
    Node* root = new Node(post[postHigh]);

    // If only one node, return it
    if (postLow == postHigh)  return root;
    

    // Find root index in inorder
    int i = inLow;
    while (i <= inHigh) {
        
        if (in[i] == post[postHigh])   break;
        i++;
    }


    // Number of nodes in left subtree
    int leftCount = i - inLow;

    // ---------------- LEFT SUBTREE ----------------
    // inorder  : inLow → i-1
    // postorder: postLow → postLow + leftCount - 1
    // (left subtree appears first in postorder)
    root->left = build(post, postLow, postLow + leftCount - 1, in, inLow, i - 1);



    // ---------------- RIGHT SUBTREE ----------------
    // inorder  : i+1 → inHigh
    // postorder: postLow + leftCount → postHigh - 1
    // (right subtree comes after left, before root)
    root->right = build(post, postLow + leftCount, postHigh - 1, in, i + 1, inHigh);

    return root;
}

// ---------------- BUILD TREE WRAPPER ----------------
Node* buildTree(vector<int>& post, vector<int>& in) {

    int n = post.size();

    // Edge case
    if (n == 0) return NULL;

    return build(post, 0, n - 1, in, 0, n - 1);
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

    vector<int> post = {9, 15, 7, 20, 3};
    vector<int> in  =  {9, 3, 15, 20, 7};

    Node* root = buildTree(post, in);

    cout << "BFS (Level Order): "<< endl;
    bfsPrint(root);

    cout << endl;

    return 0;
}