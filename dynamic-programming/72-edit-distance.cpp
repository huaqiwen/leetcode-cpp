// ID: 72
// Title: Edit Distance
// Type: Dynamic Programming
// Difficulty: Hard
// URL: https://leetcode.com/problems/edit-distance/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2);

int main() {
    string w1 = "horse", w2 = "ros";
    cout << minDistance(w1, w2) << endl;
}

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    // dp[i][j] denotes the min number of operations required to convert word1[:i] to word2[:j]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (word1[i-1] == word2[j-1]) {
                // word1[i-1] == word2[j-1], no steps needed
                dp[i][j] = dp[i-1][j-1];
            } else {
                // word1[i-1] == word2[j-1], take min of three possible operations
                dp[i][j] = min(dp[i-1][j-1] + 1,        // replace a char
                           min(dp[i-1][j] + 1,          // delete char at i
                               dp[i][j-1] + 1));        // delete char at j
            }
        }
    }

    return dp[m][n];
}
