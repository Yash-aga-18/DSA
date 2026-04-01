#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2326     Spiral Matrix IV

// given m and n, which represent the dimensions of a matrix and head of a linked list
// Generate an m x n matrix that contains the integers in the linked list 
// presented in spiral order (clockwise), starting from the top-left of the matrix. 
// If there are remaining empty spaces, fill them with -1.

/* example-->

3 → 0 → 2 → 6 → 8 → 1 → 7 → 9 → 4 → 2 → 5 → 5 → 0

3  0  2  6  8
5  0 -1 -1  1
5  2  4  9  7

*/

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Function to fill matrix in spiral order using linked list
vector<vector<int>> spiralMatrix(int m, int n, Node* head) {

    vector<vector<int>> matrix(m, vector<int>(n, -1));

    int minr = 0;
    int maxr = m - 1;
    int minc = 0;
    int maxc = n - 1;

    Node* temp = head;

    while(temp != NULL) {

        // Top row
        for(int j = minc; j <= maxc && temp != NULL; j++){
            matrix[minr][j] = temp->val;
            temp = temp->next;
        }
        minr++;

        // Right column
        for(int i = minr; i <= maxr && temp != NULL; i++){
            matrix[i][maxc] = temp->val;
            temp = temp->next;
        }
        maxc--;

        // Bottom row
        for(int j = maxc; j >= minc && temp != NULL; j--){
            matrix[maxr][j] = temp->val;
            temp = temp->next;
        }
        maxr--;

        // Left column
        for(int i = maxr; i >= minr && temp != NULL; i--){
            matrix[i][minc] = temp->val;
            temp = temp->next;
        }
        minc++;
    }

    return matrix;
}

// Helper function to print matrix
void printMatrix(vector<vector<int>>& matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    // Create linked list: 3 → 0 → 2 → 6 → 8 → 1 → 7 → 9 → 4 → 2 → 5 → 5 → 0
    Node* a = new Node(3);
    Node* b = new Node(0);
    Node* c = new Node(2);
    Node* d = new Node(6);
    Node* e = new Node(8);
    Node* f = new Node(1);
    Node* g = new Node(7);
    Node* h = new Node(9);
    Node* i = new Node(4);
    Node* j = new Node(2);
    Node* k = new Node(5);
    Node* l = new Node(5);
    Node* mNode = new Node(0);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;
    g->next = h;
    h->next = i;
    i->next = j;
    j->next = k;
    k->next = l;
    l->next = mNode;

    Node* head = a;

    int rows = 3;
    int cols = 5;

    vector<vector<int>> result = spiralMatrix(rows, cols, head);

    cout << "Spiral Matrix:" << endl;
    printMatrix(result);

    return 0;
}
