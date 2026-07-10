#include <bits/stdc++.h>
using namespace std;

// GFG----> Replace O's with X's
// leetcode Q->130   Surrounded Regions


// -------- DFS --------
void dfs(int i, int j, vector<vector<char>>& board){
    
    int n = board.size();
    int m = board[0].size();
    
    board[i][j] = '#';   // mark safe
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for(int k = 0; k < 4; k++){
        int nr = i + dr[k];
        int nc = j + dc[k];
        
        if(nr >= 0 && nr < n && nc >= 0 && nc < m 
           && board[nr][nc] == 'O'){
            
            dfs(nr, nc, board);
        }
    }
}


// -------- SOLVE --------
void solve(vector<vector<char>>& board){

    int n = board.size();
    int m = board[0].size();

    // Step 1: check first & last row
    for(int j = 0; j < m; j++){
        if(board[0][j] == 'O')   dfs(0, j, board);
        if(board[n-1][j] == 'O') dfs(n-1, j, board);
    }

    // Step 2: check first & last column
    for(int i = 0; i < n; i++){
        if(board[i][0] == 'O')   dfs(i, 0, board);
        if(board[i][m-1] == 'O') dfs(i, m-1, board);
    }

    
    // Step 3: flip remaining O → X, restore # → O
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(board[i][j] == 'O')          board[i][j] = 'X';   // captured
            else if(board[i][j] == '#')     board[i][j] = 'O';   // restore
        }
    }
}


// -------- MAIN --------
int main(){

    vector<vector<char>> board = {
        {'X','X','X','X'},
        {'X','O','O','X'},
        {'X','X','O','X'},
        {'X','O','X','X'}
    };

    solve(board);

    cout << "Final Board:\n";
    for(auto &row : board){
        for(auto c : row){
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}