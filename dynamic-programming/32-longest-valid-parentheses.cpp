// ID: 32
// Title: Longest Valid Parentheses
// Type: Dynamic Programming
// Difficulty: Hard
// URL: https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestValidParentheses(string s);

int main() {
    cout << longestValidParentheses("(()())") << endl;
    cout << longestValidParentheses("((()))(") << endl;
    cout << longestValidParentheses(")()())") << endl;
}

int longestValidParentheses(string s) {
    int n = s.size();
    // dp[i] denotes the length of the longest valid string ending at s[i]
    vector<int> dp(n, 0);

    int M = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == '(') {
            // curr char is '(', there is no valid string ending with '('
            dp[i] = 0;
        } else {
            if (s[i-1] == '(') {
                // curr char is ')' AND the one preceding it is '('
                dp[i] = (i - 2 >= 0 ? dp[i-2] : 0) + 2;
                M = max(M, dp[i]);
            } else if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(') {
                // curr char is ')' AND the one preceding it is ')' AND the char immediately precedes the longest
                // valid string ending at s[i-1] is a '(', then the LVS ending at s[i] would be 
                // dp[i-1] + 2 + dp[i-dp[i-1]-2]
                dp[i] = dp[i-1] + 2;
                if (i - dp[i-1] - 2 >= 0) dp[i] += dp[i - dp[i-1] - 2];
                M = max(M, dp[i]);
            }
        }
    }

    return M;
}
