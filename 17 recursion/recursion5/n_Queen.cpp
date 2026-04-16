#include <bits/stdc++.h>
using namespace std;

// leetcode Q->51       N-Queens



// check if placing queen at (row, col) is valid
bool isSafe(vector<string>& board, int row, int col) {

    int n = board.size();

    // check column (upwards only)
    for (int i = 0; i < row; i++) {

        if (board[i][col] == 'Q')       return false;
    
    }

    // check upper-left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {

        if (board[i][j] == 'Q')     return false;
    
    }

    // check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {

        if (board[i][j] == 'Q')     return false;
    
    }

    return true;
}


// backtracking function
void backtrack(int row, vector<string>& board, vector<vector<string>>& result) {

    int n = board.size();

    // base case → valid board
    if (row == n) {
        result.push_back(board);
        return;
    }


    // try each column
    for (int col = 0; col < n; col++) {

        if (!isSafe(board, row, col))   continue;   // skip invalid


        board[row][col] = 'Q';        // choose

        backtrack(row+1, board, result);   // explore

        board[row][col] = '.';        // undo
    }


}


vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> result;

    vector<string> board(n, string(n, '.'));  // empty board

    backtrack(0, board, result);

    return result;
}




int main() {

    int n = 4;

    vector<vector<string>> ans = solveNQueens(n);

    cout << "Total solutions: " << ans.size() << "\n\n";

    for (auto& board : ans) {
        for (auto& row : board) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}