#include <bits/stdc++.h>
using namespace std;


// -------- PRINT --------
void printList(vector<vector<int>> &adj){

    int n = adj.size() ;   // IMPORTANT FIX

    for(int i = 1; i < n; i++){
        cout << i << " --> ";
        for(auto x : adj[i]){
            cout << x << " ";
        }
        cout << endl;
    }
}


void solve(vector<vector<int>> &edges){

    // find n
    //  This assumes:
    //      Nodes are labeled from 1 to n
    //      No missing large labels (like {1,100} → then n = 100

    int n = 0;
    for(auto &e : edges){
        n = max(n, max(e[0], e[1]));
    }

    // adjacency list
    vector<vector<int>> adj(n + 1);

    for(auto &e : edges){
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);  // remove for directed
    }

    cout << "Adjacency List:\n";
    printList(adj);
}



int main()
{
    vector<vector<int>> edges = {
        {1,2}, {1,3}, 
        {2,3}, 
        {3,4} 
    };

    solve(edges);

    return 0;
}