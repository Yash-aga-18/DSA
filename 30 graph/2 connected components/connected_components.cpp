#include <bits/stdc++.h>
using namespace std;

// Connected Components in an Undirected Graph store it 


// -------- DFS --------
void dfs(int node, vector<int>& temp, vector<vector<int>>& adj, vector<int>& vis){
    
    vis[node] = 1;            // mark current node visited
    temp.push_back(node);     // store node in current component
    
    // traverse all neighbours
    for(auto neigh : adj[node]){

        if(!vis[neigh])     dfs(neigh, temp, adj, vis);
        
    }
}


// -------- SOLVE --------
vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
    
    // Step 1: build adjacency list from edge list
    vector<vector<int>> adj(V);
    
    for(auto &e : edges){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);   // undirected graph
        adj[v].push_back(u);
    }
    
    // Step 2: DFS/BFS  to find components
    vector<vector<int>> ans;
    vector<int> vis(V, 0);
    
    for(int i = 0; i < V; i++){

        if(!vis[i]){                   // new component found
        
            vector<int> temp;
            dfs(i, temp, adj, vis);   // collect all nodes of component
            ans.push_back(temp);
        }
    }
    
    return ans;
}


int main(){

    int V = 5;

    // edge list (u, v)
    vector<vector<int>> edges = {
        {0,1},
        {2,1},
        {3,4}
    };

    vector<vector<int>> components = getComponents(V, edges);

    // print result
    cout << "Connected Components:\n";
    for(auto &comp : components){
        cout << "[ ";
        for(auto x : comp){
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}