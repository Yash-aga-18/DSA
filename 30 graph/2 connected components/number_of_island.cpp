#include <bits/stdc++.h>
using namespace std;

// GFG---> Find the number of islands
// leetcode Q->200      Count no. of Islands


// on leetcode only 4 direction matters but on GFG all 8 directions are mattered
// so change the dr and dc accordingly and (loop of k) also
// and on leetcode it is 1 not 'L'


// -------- DFS --------
void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
    
    int n = grid.size();
    int m = grid[0].size();
    
    vis[i][j] = 1;   // mark visited
    
    // 8 directions (including diagonals)
    int dr[] = {-1,-1,-1, 0,0, 1,1,1};
    int dc[] = {-1, 0, 1,-1,1,-1,0,1};

    // // Only for LeetCode
    // int dr[] = {1, -1, 0, 0};
    // int dc[] = {0, 0, -1, 1};

    
    for(int k = 0; k < 8; k++){
        int nr = i + dr[k];
        int nc = j + dc[k];
        
        // check valid + land + not visited
        if(nr >= 0 && nr < n && nc >= 0 && nc < m 
           && grid[nr][nc] == 'L' && !vis[nr][nc]){
            
            dfs(nr, nc, grid, vis);
        }
    }
}


// -------- SOLVE --------
int countIslands(vector<vector<char>>& grid){
    
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m, 0));
    
    int count = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(grid[i][j] == 'L' && !vis[i][j]){
                count++;               // new island found
                dfs(i, j, grid, vis); // visit full island
            }
        }
    }
    
    return count;
}


// -------- MAIN --------
int main(){

    vector<vector<char>> grid = {
        {'W','L'},
        {'L','W'},
        {'L','L'},
        {'L','W'}
    };

    int ans = countIslands(grid);

    cout << "Number of Islands: " << ans << endl;

    return 0;
}