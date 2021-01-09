// ID: 343
// Title: Integer Break
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/integer-break/

#include <iostream>
#include <vector>

using namespace std;

int integerBreak(int n);

int main() {
    cout << integerBreak(2) << endl;
    cout << integerBreak(10) << endl;
}

int integerBreak(int n) {
    // dp[i] denotes the max integer break product up until i
    vector<int> dp(n + 1, 0);
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++)
            // at each iteration, i first gets breaked into (i-j) and (j), 
            // and each of the two can be breaked further (prev results from dp) OR stick with its original value  
            dp[i] = max(dp[i], max(dp[i-j], i-j) * max(dp[j], j));
    }

    return dp[n];
}
