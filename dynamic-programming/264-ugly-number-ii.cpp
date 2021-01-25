// ID: 264
// Title: Ugly Number II
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/ugly-number-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int nthUglyNumber(int n);

int main() {
    cout << nthUglyNumber(10) << endl;
}

int nthUglyNumber(int n) {
    vector<int> dp(n, 1);
    // p2, p3, p5 denotes indices in dp where the most number of 2 / 3 / 5's are used
    // e.g. [1, 2, 3, 4, 5, 6, 8], p2 = 6, p3 = 5, p5 = 4
    int p2 = 0, p3 = 0, p5 = 0;

    for (int i = 1; i < n; i++) {
        // e.g. we don't need #'s before p2 to be multiplied by 2, as it doesn't contain the most number of 2's 
        dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));

        // update p for new most number of 2 / 3 / 5 number index
        if (dp[p2] * 2 == dp[i]) p2++;
        if (dp[p3] * 3 == dp[i]) p3++;
        if (dp[p5] * 5 == dp[i]) p5++;
    }

    return dp[n - 1];
}
