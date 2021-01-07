// ID: 650
// Title: 2 Keys Keyboard
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/2-keys-keyboard/

#include <iostream>
#include <vector>

using namespace std;

int minSteps(int n);

int main() {
    cout << minSteps(6) << endl;
}

int minSteps(int n) {
    vector<int> dp(n + 1);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                // if i is a multiple of j, then the steps we need to get i from j is dp[i/j]
                // (think of j A's as a new A, and we need i/j new A's)
                dp[i] = dp[j] + dp[i/j];
            }
        }
    }

    return dp[n];
}
