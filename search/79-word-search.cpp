// ID: 79
// Title: Work Search
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool exist(vector<vector<char>>& board, string word);
bool backtrack(vector<vector<char>>& board, string word, int idx, int x, int y);

int main() {
    vector<vector<char>> in = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << (exist(in, "ABCCED") ? "true" : "false") << endl;

    return 0;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || board[0].size() == 0) return false;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            // if current board char is the start of word, backtrack
            if (board[i][j] == word[0] && backtrack(board, word, 0, i, j)) return true;
        }
    }

    return false;
}

bool backtrack(vector<vector<char>>& board, string word, int idx, int x, int y) {
    // reach the end of the word
    if (idx == word.size() - 1) return true;

    // modify current node's state
    board[x][y] = ' ';

    // every two consecutive elements of directions are one of the direction that we search
    vector<int> direction{-1, 0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int new_x = x + direction[i], new_y = y + direction[i+1];
        if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size()) {
            if (board[new_x][new_y] == word[idx + 1] && backtrack(board, word, idx + 1, new_x, new_y)) return true;
        }
    }
    
    // restore current node's state
    board[x][y] = word[idx];
    return false;
}
