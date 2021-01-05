// ID: 300
// Title: Longest Increasing Subsequence
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums);

int main() {
    vector<int> in = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(in) << endl;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 1;
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        max_len = max(max_len, dp[i]);
    }

    return max_len;
}
