// ID: 10
// Title: Regular Expression Matching
// Type: Dynamic Programming
// Difficulty: Hard
// URL: https://leetcode.com/problems/regular-expression-matching/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p);

int main() {
    cout << isMatch("aaa", "a*") << endl;
    cout << isMatch("aba", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
}

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();

    // dp[i][j] stores whether string s[:i] can be matched by pattern p[:j]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // handle empty string
    for (int i = 1; i <= n; i++) {
        if (p[i-1] == '*')
            dp[0][i] = dp[0][i-2];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '.')                                 // p[j-1] is '.'
                dp[i][j] = dp[i-1][j-1];
            else if (p[j-1] != '*')                            // p[j-1] is a regular char
                dp[i][j] = p[j-1] == s[i-1] && dp[i-1][j-1];
            else if (p[j-2] != s[i-1] && p[j-2] != '.')        // p[j-1] is '*', AND p[j-2] != s[i-1] AND p[j-2] != '.'
                dp[i][j] = dp[i][j-2];                         // last 2 pattern char does not match, but '*' can be 0
            else                                               // p[j-1] is '*', AND (p[j-2] == s[i-1] OR p[j-2] == '.')
                dp[i][j] = dp[i][j-1] || dp[i-1][j] || dp[i][j-2];
        }
    }

    return dp[m][n];
}
