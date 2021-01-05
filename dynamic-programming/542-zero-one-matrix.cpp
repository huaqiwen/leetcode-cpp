// ID: 542
// Title: 01 Matrix
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/01-matrix/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix);

int main() {
    vector<vector<int>> m = {{0,1,0,1,1},
                             {1,1,0,0,1},
                             {0,0,0,1,0},
                             {1,0,1,1,1},
                             {1,0,0,0,1}};
    for (vector<int> row : updateMatrix(m)) {
        for (int n : row)
            cout << n << " ";
        cout << endl;
    }
}

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT32_MAX - 1));

    // First time do a dynamic search from top left to bottom right, i.e.,
    // everytime search for left/top dp records.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                dp[i][j] = 0;
            } else if (i > 0 && j > 0) {
                dp[i][j] = min(dp[i][j], 1 + min(dp[i-1][j], dp[i][j-1]));
            } else if (j > 0) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j-1]);
            } else if (i > 0) {
                dp[i][j] = min(dp[i][j], 1 + dp[i-1][j]);
            }
        }
    }

    // Second time do a dynamic search from bottom right to top left, i.e.,
    // everytime search for bottom/right dp records.
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i < m - 1 && j < n - 1){
                dp[i][j] = min(dp[i][j], 1 + min(dp[i+1][j], dp[i][j+1]));
            } else if (j < n - 1) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][j+1]);
            } else if (i < m - 1) {
                dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
            }
        }
    }

    return dp;
}
