#include <bits/stdc++.h>
using namespace std;

class Node{
 public: 
    
    int val;
    Node *left;
    Node *right;

    Node(int val){
        this->val   = val;
        this->left  = NULL;
        this->right = NULL;
    }

};


void display(Node* root){

    if(root == NULL)    return;

    cout<<root->val <<" ";
    
    display(root->left);
    display(root->right);
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

int sum(Node* root){

    if(root == NULL)    return 0;

    
    int left_sum = sum(root->left);
    int right_sum = sum(root->right);

    return (root->val + left_sum + right_sum);
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

int size(Node* root){

    if(root == NULL)    return 0;

    
    int left_sum =  size(root->left);
    int right_sum = size(root->right);

    return (1 + left_sum + right_sum);
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

int max_val(Node* root){

    if(root == NULL) return INT_MIN;

    int left_max = max_val(root->left);
    int right_max = max_val(root->right);

    return max(root->val, max(left_max, right_max));
    
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

int level(Node* root){

    if(root == NULL)    return 0;

    
    int left_level =  level(root->left);
    int right_level = level(root->right);

    return (1 + max(left_level, right_level));
}

//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------



int main()
{
    
    Node* a = new Node(1);    
    Node* b = new Node(2);    
    Node* c = new Node(3);    
    Node* d = new Node(4);    
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);
    Node* h = new Node(8);
    
    a->left  = b;
    a->right = c;
    b->left  = d;
    b->right = e;
    c->left  = f;
    c->right = g;
    d->left  = h;

    Node* root = a;

    display(root);
    cout<<endl;

    cout<<"Total sum is -> "<< sum(root);
    cout<<endl;
    
    cout<<"Total size is -> "<< size(root);
    cout<<endl;
    
    cout<<"Max Element -> "<< max_val(root);
    cout<<endl;
    
    cout<<"Total Levels -> "<< level(root);
    cout<<endl;
    
    cout<<"Total Height -> "<< level(root) -1;
    cout<<endl;

 return 0;

}