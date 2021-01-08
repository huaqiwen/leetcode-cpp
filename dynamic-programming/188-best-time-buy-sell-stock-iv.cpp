// ID: 188
// Title: Best Time to Buy and Sell Stock IV
// Type: Dynamic Programming
// Difficulty: Hard
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices);
int maxProfitUnlimited(vector<int>& prices);

int main() {
    vector<int> in = {3, 2, 6, 5, 0, 3};
    cout << maxProfit(2, in) << endl;
}

int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    if (days < 2) return 0;
    if (k > days / 2) return maxProfitUnlimited(prices);        // k > days implies we have unlimited buys and sells

    // We have a total of k transactions, i.e., we have k buys and k sells.
    // Here buy[j] denotes the max profit after the j-th buy, 
    // and sell[j] denotes the max profit after the j-th sell.
    vector<int> buy(k + 1, INT32_MIN), sell(k + 1, 0);
    for (int i = 0; i < days; i++) {
        for (int j = 1; j <= k; j++) {
            buy[j] = max(buy[j], sell[j-1] - prices[i]);
            sell[j] = max(sell[j], buy[j] + prices[i]);
        }
    }

    return sell[k];
}

/**
 * @brief same as 122. Best Time to Buy and Sell Stock II
 */
int maxProfitUnlimited(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] >= prices[i-1]) profit += prices[i] - prices[i-1];
    
    return profit;
}
