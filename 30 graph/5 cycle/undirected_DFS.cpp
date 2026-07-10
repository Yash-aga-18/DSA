#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis) {

    vis[node] = 1;

    for (auto neigh : adj[node]) {

        if (!vis[neigh]) {
            if (dfs(neigh, node, adj, vis)) return true;
        }

        else if (neigh != parent)   return true;
        
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> &adj) {

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis)) return true;
        }
    }
    return false;
}



int main() {

    int V = 5;
    vector<vector<int>> adj = {
        {1}, {0,2}, {1,3}, {2,4}, {3}
    };

    cout << isCycle(V, adj);

    return 0;
}