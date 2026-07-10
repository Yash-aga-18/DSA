#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>> &adj, vector<int> &vis) {

    queue< pair<int,int> > q;

    q.push({start, -1});
    vis[start] = 1;

    while (!q.empty()) {

        int node    = q.front().first;
        int parent  = q.front().second;
        q.pop();

        for (auto neigh : adj[node]) {

            if (!vis[neigh]) {
                vis[neigh] = 1;
                q.push({neigh, node});
            }

            else if (neigh != parent)       return true;
            
        }
    }
    return false;
}



bool isCycle(int V, vector<vector<int>> &adj) {

    vector<int> vis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (bfs(i, adj, vis))   return true;
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