#include <bits/stdc++.h>
using namespace std;

// GFG---> BFS of graph         just return a vector storing bfs


// -------- BFS HELPER --------
void bfsHelper(int start, vector<vector<int>> &adj, vector<int> &res) {

    int n = adj.size();

    vector<int> vis(n, 0);
    queue<int> q;

    q.push(start);
    vis[start] = 1;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        res.push_back(node);

        for (int neigh : adj[node]) {

            if (vis[neigh] == 0) {

                vis[neigh] = 1;
                q.push(neigh);
            }

        }

    }
}


// -------- MAIN BFS --------
vector<int> bfs(vector<vector<int>> &adj) {

    vector<int> res;

    bfsHelper(0, adj, res);

    return res;
}



int main() {

    int n = 5;

    vector<vector<int>> adj(n);

    // Graph
    adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = bfs(adj);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}