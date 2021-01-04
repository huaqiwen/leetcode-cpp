// ID: 37
// Title: Sudoku Solver
// Type: Search
// Difficulty: Hard
// URL: https://leetcode.com/problems/sudoku-solver/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

void solveSudoku(vector<vector<char>>& board);
void backtrack(vector<vector<char>>& board, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& boxes, int x, int y, vector<pair<int, int>>& visited);

int main() {
    vector<vector<char>> bd = {{'5','3','.','.','7','.','.','.','.'},
                               {'6','.','.','1','9','5','.','.','.'},
                               {'.','9','8','.','.','.','.','6','.'},
                               {'8','.','.','.','6','.','.','.','3'},
                               {'4','.','.','8','.','3','.','.','1'},
                               {'7','.','.','.','2','.','.','.','6'},
                               {'.','6','.','.','.','.','2','8','.'},
                               {'.','.','.','4','1','9','.','.','5'},
                               {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(bd);
    for (vector<char>& row : bd) {
        for (char c : row)
            cout << c << " ";
        cout << endl;
    }
}

void solveSudoku(vector<vector<char>>& board) {
    // init rows, cols, boxes
    vector<vector<bool>> rows(9, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    vector<vector<bool>> cols(9, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    vector<vector<bool>> boxs(9, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});       // I didn't use "boxes" to keep it 4 letters :)
    vector<pair<int, int>> visited;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int n = board[i][j] - '0';
                rows[i][n] = true;
                cols[j][n] = true;
                boxs[(i / 3) * 3 + j / 3][n] = true;
            }
        }
    }
    backtrack(board, rows, cols, boxs, 0, 0, visited);
}

void backtrack(vector<vector<char>>& board, vector<vector<bool>>& rows, vector<vector<bool>>& cols, vector<vector<bool>>& boxes, int x, int y, vector<pair<int, int>>& visited) {
    vector<int> directions = {-1, 0, 1, 0, -1};

    // empty node, try numbers
    if (board[y][x] == '.') {
        for (int k = 1; k <= 9; k++) {
            // check if new number is valid (board[y][x])
            if (rows[y][k] || cols[x][k] || boxes[(y / 3) * 3 + x / 3][k]) continue;
            
            // update board, rows, cols, boxes, visited
            board[y][x] = k + '0';
            rows[y][k] = true; cols[x][k] = true; boxes[(y / 3) * 3 + x / 3][k] = true;
            visited.push_back({x, y});

            // backtrack all possible directions if not visited
            for (int i = 0; i < 4; i++) {
                int nx = x + directions[i], ny = y + directions[i+1];
                pair<int, int> p = {nx, ny};
                if (count(visited.begin(), visited.end(), p)) continue;

                if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
                    backtrack(board, rows, cols, boxes, nx, ny, visited);

                    // check if board full
                    if (visited.size() == 81) return;

                    // visited is not full, backtrack failed, restore board, rows, cols, boxes
                    board[y][x] = '.';
                    rows[y][k] = false; cols[x][k] = false; boxes[(y / 3) * 3 + x / 3][k] = false;
                    visited.pop_back();

                    // if one direction fails, no other ways will work, break
                    break;
                }
            }
        }
    
    // non-empty nodes, continue trying
    } else {

        visited.push_back({x, y});
        // backtrack all possible directions if not visited
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i], ny = y + directions[i+1];
            pair<int, int> p = {nx, ny};
            if (count(visited.begin(), visited.end(), p)) continue;
            
            if (nx >= 0 && nx < 9 && ny >= 0 && ny < 9) {
                backtrack(board, rows, cols, boxes, nx, ny, visited);
                // check if board full
                if (visited.size() == 81) return;

                visited.pop_back();
                break;
            }
        }
    }
}
