// ID: 64
// Title: Minimum Path Sum
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid);
void minPathSumAtPoint(vector<vector<int>>& grid, vector<vector<int>>& dp, int x, int y);

int main() {
    vector<vector<int>> gd = {{1, 3, 1},
                              {1, 5, 1},
                              {4, 2, 1}};
    cout << minPathSum(gd) << endl;
}

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();

    // dp stores the min sum to bottom right from each spot
    vector<vector<int>> dp = {};
    for (int i = 0; i < m; i++) {
        vector<int> row = {};
        for (int j = 0; j < n; j++) row.push_back(-1);
        dp.push_back(row);
    }

    minPathSumAtPoint(grid, dp, 0, 0);
    return dp[0][0];
}

void minPathSumAtPoint(vector<vector<int>>& grid, vector<vector<int>>& dp, int x, int y) {
    int m = grid.size(), n = grid[0].size();
    // bottom right reached
    if (y == m - 1 && x == n - 1) {
        dp[y][x] = grid[y][x];
        return;
    }

    // non-bottom right point, min step to BR point is self pt + min(right cumu pts, down cumu pts)
    if (x + 1 < n && dp[y][x+1] == -1) minPathSumAtPoint(grid, dp, x + 1, y);
    if (y + 1 < m && dp[y+1][x] == -1) minPathSumAtPoint(grid, dp, x, y + 1);
    
    int down_memo = y == m - 1 ? INT32_MAX : dp[y+1][x];
    int rght_memo = x == n - 1 ? INT32_MAX : dp[y][x+1];
    dp[y][x] = grid[y][x] + min(down_memo, rght_memo);
}
