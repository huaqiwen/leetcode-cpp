// ID: 322
// Title: Coin Change
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount);

int main() {
    vector<int> in = {1, 2, 5};
    cout << coinChange(in, 11) << endl;
}

int coinChange(vector<int>& coins, int amount) {
    if (coins.empty()) return -1;

    // init dp with (amount + 2) as the it's not possible to be the fewest # coins we need for index amount 
    vector<int> dp(amount + 1, amount + 2);
    dp[0] = 0;
    
    // this is essentially an unbounded knapsack problem
    for (int i = 1; i <= amount; i++) {
        for (const int& coin : coins) {
            if (i >= coin) 
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    return dp[amount] == amount + 2 ? -1 : dp[amount];
}
