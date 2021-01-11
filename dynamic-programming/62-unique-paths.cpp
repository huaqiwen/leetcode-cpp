// ID: 62
// Title: Unique Paths
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n);

int main() {
    cout << uniquePaths(3, 7) << endl;
}

int uniquePaths(int m, int n) {
    // dp[i][j] denotes # unique paths from top-left to grid[i][j]
    // TODO: since we only use the values from the last "layer", we can compress dp array to 1D
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
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
