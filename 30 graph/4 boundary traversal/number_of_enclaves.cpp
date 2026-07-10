#include <bits/stdc++.h>
using namespace std;

// leetcode Q->1020  Number of Enclaves


// -------- DFS --------
void dfs(int i, int j, vector<vector<int>>& grid){
    
    int n = grid.size();
    int m = grid[0].size();
    
    grid[i][j] = 0;   // remove land (mark visited)
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for(int k = 0; k < 4; k++){
        int nr = i + dr[k];
        int nc = j + dc[k];
        
        if(nr >= 0 && nr < n && nc >= 0 && nc < m 
           && grid[nr][nc] == 1){
            
            dfs(nr, nc, grid);
        }
    }
}


// -------- SOLVE --------
int numEnclaves(vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    // Step 1: remove boundary-connected land
    for(int j = 0; j < m; j++){
        if(grid[0][j] == 1)     dfs(0, j, grid);
        if(grid[n-1][j] == 1)   dfs(n-1, j, grid);
    }

    for(int i = 0; i < n; i++){
        if(grid[i][0] == 1)     dfs(i, 0, grid);
        if(grid[i][m-1] == 1)   dfs(i, m-1, grid);
    }

    // Step 2: count remaining land
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 1){
                count++;
            }
        }
    }

    return count;
}


// -------- MAIN --------
int main(){

    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    int ans = numEnclaves(grid);

    cout << "Number of Enclaves: " << ans << endl;

    return 0;
}