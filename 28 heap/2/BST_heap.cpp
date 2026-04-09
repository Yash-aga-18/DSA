#include <bits/stdc++.h>
using namespace std;

// convert BST --> Max Heap

// convert BST --> Min Heap



class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Step 1: store inorder (sorted)
void inorder(Node* root, vector<int>& v) {
    if(root == NULL) return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

// Step 2: fill using preorder
void preorderFill(Node* root, vector<int>& v, int &i) {
    if(root == NULL) return;

    root->data = v[i++];

    preorderFill(root->left,  v, i);
    preorderFill(root->right, v, i);
}

// main conversion function
void convertToMinHeap(Node* root) {
    vector<int> v;

    inorder(root, v);
    // reverse(v.begin(), v.end());    //  just use this line to get max-heap, it reverses the vector

    int i = 0;
    preorderFill(root, v, i);
}




void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main() {

    /*
            4
          /   \
         2     6
        / \   / \
       1   3 5   7
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertToMinHeap(root);

    cout << "Level Order of Min Heap: ";
    levelOrder(root);

    return 0;
}



/*
Convert BST to Min Heap.  Total Methods: 2

-------------------------------------
Method 1: Inorder + Preorder (Most Important)

Steps:
1. Do inorder traversal of BST → get sorted array
2. Traverse tree in preorder
3. Replace node values using sorted array

Why it works:
- Inorder of BST = sorted order
- Preorder ensures parent is filled before children
→ So min heap property is maintained

-------------------------------------
Method 2: Store + Level Order Fill

Steps:
1. Store all values (inorder preferred → sorted)
2. Traverse tree in level order (BFS)
3. Fill values from sorted array

Why it works:
- Level order ensures complete binary tree structure
- Filling from sorted ensures min heap

-------------------------------------
Time Complexity:    O(n)
Space Complexity:   O(n)

*/