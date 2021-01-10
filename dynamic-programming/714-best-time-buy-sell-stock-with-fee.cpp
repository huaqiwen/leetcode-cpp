// ID: 714
// Title: Best Time to Buy and Sell Stock with Transaction Fee
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices, int fee);

int main() {
    vector<int> in = {1, 3, 2, 8, 4, 9};
    cout << maxProfit(in, 2) << endl;
}

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if (n == 0) return 0;

    // simple state machine solution, similar to 188 & 309
    vector<int> buy(n), sell(n);
    buy[0] = -prices[0];
    sell[0] = 0;

    for (int i = 1; i < n; i++) {
        buy[i] = max(buy[i-1], sell[i-1] - prices[i]);
        sell[i] = max(sell[i-1], buy[i-1] + prices[i] - fee);
    }

    return sell[n-1];
}
