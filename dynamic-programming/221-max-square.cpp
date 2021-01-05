// ID: 221
// Title: Maximal Square
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/maximal-square/

#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix);

int main() {
    vector<vector<char>> m = {{'1','0','1','0','0'},
                              {'1','0','1','1','1'},
                              {'1','1','1','1','1'},
                              {'1','0','0','1','0'}};
    cout << maximalSquare(m) << endl;
}

int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), max_side_len = 0;
    // 2d vector dp represents the maximal square's *side length* and is the bottom-right corner of the square
    vector<vector<int>> dp(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                max_side_len = max(max_side_len, matrix[i][j] - '0');
                dp[i][j] = matrix[i][j] - '0';
            } else if (matrix[i][j] - '0' == 1) {
                // If the bottom right coner is '1', and the three neighbours (left, top, top-left) all have
                // maximal square side length at least (k-1), then this bottom right corner has maximal square
                // side length k.
                int min_neigh = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                max_side_len = max(max_side_len, min_neigh + 1);
                dp[i][j] = min_neigh + 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return max_side_len * max_side_len;
}
