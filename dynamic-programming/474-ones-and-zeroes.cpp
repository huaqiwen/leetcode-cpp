// ID: 474
// Title: Ones and Zeroes
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/ones-and-zeroes/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int findMaxForm(vector<string>& strs, int m, int n);

int main() {
    vector<string> in = {"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(in, 5, 3) << endl;
}

int findMaxForm(vector<string>& strs, int m, int n) {
    // dp[i][j] denotes the size of the largest subset from strs that has at most i 0's and j 1's
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (const string& str : strs) {
        int c0 = count(str.begin(), str.end(), '0'), c1 = count(str.begin(), str.end(), '1');
        for (int i = m; i >= c0; i--) {
            for (int j = n; j >= c1; j--) {
                dp[i][j] = max(dp[i][j], dp[i - c0][j - c1] + 1);
            }
        }
    }

    return dp[m][n];
}
