#include <bits/stdc++.h>
using namespace std;

// GFG-----> The Knight's tour problem


// knight moves
vector<int> dr = {2,2,-2,-2,1,1,-1,-1};
vector<int> dc = {1,-1,1,-1,2,-2,2,-2};


// backtracking function
bool backtrack(int r, int c, int move, vector<vector<int>>& board, int n) {

    // if all cells visited
    if (move == n*n)        return true;

    // try all 8 moves
    for (int i = 0; i < 8; i++) {

        int nr = r + dr[i];
        int nc = c + dc[i];

        // check valid position and not visited
        if (nr >= 0 && nc >= 0 && nr < n && nc < n && board[nr][nc] == -1) {

            board[nr][nc] = move;   // choose

            if (backtrack(nr, nc, move+1, board, n))    return true;        // solution found

            board[nr][nc] = -1;     // undo (backtrack)
        }
    }

    return false;   // no move works
}


// main function
vector<vector<int>> knightTour(int n) {

    vector<vector<int>> board(n, vector<int>(n, -1));

    board[0][0] = 0;   // start from (0,0)

    if (backtrack(0, 0, 1, board, n))   return board;

    return {};   // no solution
}


int main() {

    int n = 5;

    vector<vector<int>> ans = knightTour(n);

    if (ans.empty()) {
        cout << "No solution\n";
    } else {
        for (auto &row : ans) {
            for (auto x : row) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}