#include <bits/stdc++.h>
using namespace std;

// leetcode Q->547    Number of Provinces


// -------- DFS --------
void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
    
    vis[node] = 1;

    for (int j = 0; j < adj.size(); j++) {

        if (adj[node][j] == 1 && vis[j] == 0) {
            dfs(j, adj, vis);
        }
        
    }
}


// -------- BFS --------    can also be used nstead of DFS
void bfs(int start, vector<vector<int>>& adj, vector<int>& vis){

    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while(!q.empty()){

        int node = q.front();
        q.pop();

        for (int j = 0; j < adj.size(); j++) {

            if (adj[node][j] == 1 && vis[j] == 0) {
                vis[j] = 1;
                q.push(j);
            }
        }
    }
}



// -------- SOLVE --------
int findCircleNum(vector<vector<int>>& adj) {

    int n = adj.size();

    vector<int> vis(n, 0);
    int count = 0;

    for(int i = 0; i < n; i++){
        if(!vis[i]){
            count++;
            dfs(i, adj, vis);
            // bfs(i, adj, vis);
        }
    }

    return count;
}



int main() {

    vector<vector<int>> adj = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    int ans = findCircleNum(adj);

    cout << "Number of Provinces: " << ans << endl;

    return 0;
}