// ID: 309
// Title: Best Time to Buy and Sell Stock with Cooldown
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
    vector<int> in = {1, 2, 3, 0, 2};
    cout << maxProfit(in) << endl;
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;

    // FSM approach: each states to denote a senario (buy, sell, cooldown, no action) and its max profit on a given day.
    // Transform functions:
    // <buy> + price => <sell>
    // <buy>         => <s1>
    // <s1>          => <s1>
    // <s1> + price  => <sell>
    // <sell>        => <s2>
    // <s1>          => <s2>
    // <s2> - price  => <buy>
    vector<int> buy(n), sell(n), s1(n), s2(n);
    s1[0] = buy[0] = -prices[0];
    sell[0] = s2[0] = 0;

    for (int i = 1; i < n; i++) {
        buy[i] = s2[i-1] - prices[i];
        s1[i] = max(s1[i-1], buy[i-1]);
        sell[i] = max(buy[i-1] + prices[i], s1[i-1] + prices[i]);
        s2[i] = max(s2[i-1], sell[i-1]);
    }

    return max(sell[n-1], s2[n-1]);

    // The code below slightly reduces the memory usage. 
    {
    // int buy, sell, s1, s2;
    // buy = s1 = -prices[0];
    // sell = s2 = 0;

    // for (int i = 1; i < n; i++) {
    //     int nbuy = s2 - prices[i];
    //     int ns1 = max(s1, buy);
    //     int nsell = max(buy + prices[i], s1 + prices[i]);
    //     int ns2 = max(s2, sell);

    //     buy = nbuy; s1 = ns1; sell = nsell; s2 = ns2;
    // }

    // return max(sell, s2);
    }
}
