// ID: 338
// Title: Counting Bits
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/counting-bits/

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int num);

int main() {
    for (int ans : countBits(5))
        cout << ans << " ";
    cout << endl;
}

vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);

    for (int i = 1; i <= num; i++) {
        // # 1's in bin(i) should be # 1's in bin(i / 2) + (odd(i) ? 1 : 0)
        dp[i] = dp[i / 2] + (i % 2 == 1 ? 1 : 0);
    }

    return dp;
}
