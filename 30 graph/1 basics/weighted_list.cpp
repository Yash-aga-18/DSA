#include <bits/stdc++.h>
using namespace std;

// -------- PRINT --------
void printList(vector<vector<pair<int,int>>> &adj){

    int n = adj.size();

    for(int i = 1; i < n; i++){
        cout << i << " --> ";
        for(auto x : adj[i]){
            cout << "(" << x.first << "," << x.second << ") ";
        }
        cout << endl;
    }
}


// -------- SOLVE --------
void solve(vector<vector<int>> &edges){

    // find n
    int n = 0;
    for(auto &e : edges){
        n = max(n, max(e[0], e[1]));
    }

    // adjacency list (weighted)
    vector<vector <pair<int,int>> > adj(n + 1);

    for(auto &e : edges){

        int u = e[0];
        int v = e[1];
        int w = e[2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // remove for directed 
    }

    cout << "Weighted Adjacency List:\n";
    printList(adj);
}


// -------- MAIN --------
int main()
{
    vector<vector<int>> edges = {
        {1,2,  4}, 
        {1,3,  2}, 
        {2,3,  5}, 
        {3,4,  1}
    };

    solve(edges);

    return 0;
}