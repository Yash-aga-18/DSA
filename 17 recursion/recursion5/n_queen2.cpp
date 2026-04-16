#include <bits/stdc++.h>
using namespace std;

// leetcode Q->52       N-Queens2


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
void backtrack(int row, vector<string>& board, int& count) {

    int n = board.size();

    // base case → valid board
    if (row == n) {
        count++;           // count instead of storing
        return;
    }


    // try each column
    for (int col = 0; col < n; col++) {

        if (!isSafe(board, row, col))   continue;   // skip invalid


        board[row][col] = 'Q';        // choose

        backtrack(row+1, board, count);   // explore

        board[row][col] = '.';        // undo
    }
}


int totalNQueens(int n) {

    int count = 0;

    vector<string> board(n, string(n, '.'));  // empty board

    backtrack(0, board, count);

    return count;
}



int main() {

    int n = 4;

    int ans = totalNQueens(n);

    cout << "Total solutions: " << ans << "\n";

    return 0;
}