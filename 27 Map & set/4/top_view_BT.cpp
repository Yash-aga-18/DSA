#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// Function to get Top View
vector<int> topView(Node* root)
{
    vector<int> ans;
    if(root == NULL)    return ans;

    // map: horizontal distance → node value
    map<int, int> mp;

    // queue: pair of (node, horizontal distance)
    queue<pair<Node*, int>> q;
    q.push({root, 0});


    while(!q.empty())
    {
        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        // store first node at each horizontal distance
        // this line means that we didn't find the horizontal distance for it 
        if(mp.find(hd) == mp.end())     mp[hd] = node->data;

        // push left child
        if(node->left != NULL)      q.push({node->left, hd-1});

        // push right child
        if(node->right != NULL)     q.push({node->right, hd+1});
    }

    // extract result in sorted order of hd
    for(auto ele : mp)       ans.push_back(ele.second);

    return ans;
}


//  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Function to get Bottom View
vector<int> bottomView(Node* root)
{
    vector<int> ans;
    if(root == NULL)    return ans;

    // map: horizontal distance → node value
    map<int, int> mp;

    // queue: pair of (node, horizontal distance)
    queue<pair<Node*, int>> q;
    q.push({root, 0});


    while(!q.empty())
    {
        auto front = q.front();
        q.pop();

        Node* node = front.first;
        int hd = front.second;

        // only this condn will changed , Here we didnt check the existing as it 
        // overwrites previous → keeps bottom-most
        mp[hd] = node->data;

        // push left child
        if(node->left != NULL)      q.push({node->left, hd-1});

        // push right child
        if(node->right != NULL)     q.push({node->right, hd+1});
    }

    // extract result in sorted order of hd
    for(auto ele : mp)       ans.push_back(ele.second);

    return ans;
}


int main()
{
    /*
            1
          /   \
         2     3
          \   / \
           4 5   6
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    vector<int> res = topView(root);
    for(int x : res)    cout << x << " ";
    cout<<endl;    

    vector<int> res1 = bottomView(root);
    for(int x : res1)   cout << x << " ";
    
    
    
    return 0;
}