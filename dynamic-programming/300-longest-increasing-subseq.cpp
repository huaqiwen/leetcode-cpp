// ID: 300
// Title: Longest Increasing Subsequence
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums);
int lengthOfLIS2(vector<int>& nums);

int main() {
    vector<int> in = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS2(in) << endl;
}

/**
 * @brief Brute force dp, O(n^2)
 */
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), max_len = 1;
    // dp stores the length of the LIS ending at nums[index]
    vector<int> dp(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        max_len = max(max_len, dp[i]);
    }

    return max_len;
}

/**
 * @brief Better dp, O(nlogn)
 */
int lengthOfLIS2(vector<int>& nums) {
    int n = nums.size();
    if (n <= 1) return n;
    // dp stores the smallest number in nums that can be the end of a IS with length index + 1
    vector<int> dp = {nums[0]};

    for (int i = 1; i < n; i++) {
        if (nums[i] > dp.back()) {
            dp.push_back(nums[i]); 
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), nums[i]);
            *it = nums[i];
        }
    }

    return dp.size();
}
