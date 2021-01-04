// ID: 130
// Title: Surrounded Regions
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/surrounded-regions/

#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& board);
void dfs(vector<vector<char>>& board, int x, int y);

int main() {
    vector<vector<char>> bd = {{'X', 'X', 'X', 'X'},
                               {'X', 'O', 'O', 'X'},
                               {'X', 'X', 'O', 'X'},
                               {'X', 'O', 'X', 'X'}};
    solve(bd);
    for (vector<char>& row : bd) {
        for (char c : row)
            cout << c << ' ';
        cout << endl;
    }
}

void solve(vector<vector<char>>& board) {
    if (board.size() <= 2 || board[0].size() <= 2) return;

    // mark all free nodes as 'F'
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // if current node is a border node and is open, dfs to flip all its connected nodes
            if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                dfs(board, j, i);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 'O')
                board[i][j] = 'X';
            else if (board[i][j] == 'F')
                board[i][j] = 'O';
        }
    }
}

void dfs(vector<vector<char>>& board, int x, int y) {
    board[y][x] = 'F';

    vector<int> directions = {-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i], ny = y + directions[i+1];
        if (nx >= 0 && nx < board[0].size() && ny >= 0 && ny < board.size() && board[ny][nx] == 'O') {
            dfs(board, nx, ny);
        }
    }
}
