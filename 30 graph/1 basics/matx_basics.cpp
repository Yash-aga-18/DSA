#include <bits/stdc++.h>
using namespace std;


void printmtx(vector<vector<int>> &adj){

    int n = adj.size() ;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}


void solve(vector<vector<int>> &edges){

    // find n
    int n = 0;
    for(auto &e : edges){
        n = max(n, max(e[0], e[1]));
    }

    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
    
        adj[u][v] = 1;
        adj[v][u] = 1;  // remove for directed graph
    }

    cout << "Matrix Traversal:\n";
    printmtx(adj);
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