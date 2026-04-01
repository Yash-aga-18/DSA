#include <bits/stdc++.h>
using namespace std;

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


// construct tree from level order array
Node* const_tr(vector<int>& arr) {

    if (arr.size() == 0 || arr[0] == INT_MIN) return NULL;

    Node* root = new Node(arr[0]);

    queue<Node*> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < arr.size()) {

        Node* temp = q.front();
        q.pop();

        // LEFT CHILD
        if (i < arr.size() && arr[i] != INT_MIN) {
            Node* l = new Node(arr[i]);
            temp->left = l;
            q.push(l);
        }
        i++;

        // RIGHT CHILD
        if (i < arr.size() && arr[i] != INT_MIN) {
            Node* r = new Node(arr[i]);
            temp->right = r;
            q.push(r);
        }
        i++;
    }

    return root;
}



int main() {

    vector<int> arr = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};

    Node* root = const_tr(arr);

    return 0;
}