// ID: 63
// Title: Unique Paths II
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid);

int main() {
    vector<vector<int>> in = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    cout << uniquePathsWithObstacles(in) << endl;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    // dp[i][j] denotes # unique paths from top-left to grid[i][j]
    // TODO: since we only use the values from the last "layer", we can compress dp array to 1D
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // if current node is obstacle, than there is no way getting here
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
        
            if (i > 0) {
                dp[i][j] += dp[i-1][j];
            }
            if (j > 0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}
