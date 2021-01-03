// ID: 51
// Title: N-Queens
// Type: Search
// Difficulty: Hard
// URL: https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string>> solveNQueens(int n);
void backtrack(vector<vector<string>>& ans, 
               vector<string>& board, vector<bool>& col, vector<bool> ldiag, vector<bool> rdiag, 
               int row, int n);

int main() {
    for (vector<string>& sol : solveNQueens(4)) {
        for (string& row : sol)
            cout << row << endl;
        cout << "------" << endl;
    }

    return 0;
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    if (n == 0) return ans;

    vector<string> board(n, string(n, '.'));
    // note that as we insert queens w.r.t each rows, we don't need to visit rows to check for other queens,
    // ldiag and rdiag each represents the (2n-1) diagonals of the board 
    vector<bool> col(n, false), ldiag(2*n-1, false), rdiag(2*n-1, false);
    backtrack(ans, board, col, ldiag, rdiag, 0, n);
    return ans;
}

void backtrack(vector<vector<string>>& ans, vector<string>& board, 
               vector<bool>& col, vector<bool> ldiag, vector<bool> rdiag, 
               int row, int n) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i] || ldiag[n-row+i-1] || rdiag[row+i]) continue;

        // modify current node's state
        board[row][i] = 'Q';
        col[i] = ldiag[n-row+i-1] = rdiag[row+i] = true;

        // recurse child nodes
        backtrack(ans, board, col, ldiag, rdiag, row + 1, n);

        // restore current node's state
        board[row][i] = '.';
        col[i] = ldiag[n-row+i-1] = rdiag[row+i] = false;
    }
}
