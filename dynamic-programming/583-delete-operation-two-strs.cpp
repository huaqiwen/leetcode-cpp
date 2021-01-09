// ID: 583
// Title: Delete Operation for Two Strings
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/delete-operation-for-two-strings/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minDistance(string word1, string word2);
int longestCommonSubsequence(string text1, string text2);

int main() {
    cout << minDistance("sea", "eat") << endl;
}

int minDistance(string word1, string word2) {
    return word1.size() + word2.size() - 2 * longestCommonSubsequence(word1, word2);
}

/**
 * @brief same as 1143. Longest Common Subsequence
 */
int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    // dp[i][j] stores the longest common subseq until text1 reaches i and text2 reaches j
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text1[i - 1] == text2[j - 1])       // extend LCS
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][ j -1]);
        }
    }

    return dp[m][n];
}
