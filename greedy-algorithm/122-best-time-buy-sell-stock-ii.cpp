// ID: 122
// Title: Best Time to Buy and Sell Stock II
// Type: Greedy Algorithm
// Difficulty: Easy
// URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices);

int main() {
    vector<int> p = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(p) << endl;

    return 0;
}


int maxProfit(vector<int>& prices) {
    // First, if a sequence in the array is monotonic non-decreasing, then clearly the max profit is 
    // sequence[-1] - sequence[0] = sum(cnosecutive differences).
    // 
    // Thus, we add the difference if current price is greater than prev price, 
    // and do nothing if current price is less than prev price.

    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
        if (prices[i] >= prices[i-1]) profit += prices[i] - prices[i-1];
    
    return profit;
}
