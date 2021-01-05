// ID: 139
// Title: Word Break
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/word-break/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict);

int main() {
    vector<string> in = {"cats", "dog", "sand", "and", "cat"};
    cout << (wordBreak("catsandog", in) ? "true" : "false") << endl;
    cout << (wordBreak("catsanddog", in) ? "true" : "false") << endl;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    // dp stores whether the substring ending at index can be broken into dict words
    vector<bool> dp(n, false);

    for (int i = 0; i < n; i++) {
        for (string word : wordDict) {
            int word_len = word.size();
            // word size == curr str size AND word == curr str
            if (word_len == i + 1 && s.substr(i - word_len + 1, word_len) == word)
                dp[i] = true;
            // word size < curr str size AND word == last part of curr str AND the str before the word can be broken
            if (word_len < i + 1 && s.substr(i - word_len + 1, word_len) == word && dp[i - word_len])
                dp[i] = true;
        }
    }

    return dp[n - 1];
}
