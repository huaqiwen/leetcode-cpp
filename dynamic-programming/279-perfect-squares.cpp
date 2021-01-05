// ID: 279
// Title: Perfect Squares
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>

using namespace std;

int numSquares(int n);

int main() {
    cout << numSquares(12) << endl;
    cout << numSquares(13) << endl;
}

int numSquares(int n) {
    vector<int> dp(n + 1, INT32_MAX);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}
