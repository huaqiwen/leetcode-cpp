// ID: 494
// Title: Target Sum
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findTargetSumWays(vector<int>& nums, int S);

int main() {
    vector<int> in = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(in, 3) << endl;
}

int findTargetSumWays(vector<int>& nums, int S) {
    // Since there are only addition and subtraction, the value of any equations is essentially
    // a - b, where a is the sum of a group of nums and b is the sum of the remaining numbers.
    // Then as sum(nums) = a + b, we have a = (S + sum(nums)) / 2,
    // and we will get the number of ways to obtain a using similar method to Q416. Partition Equal Subset Sum.
    int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
    if (sum < S || (sum + S) % 2 != 0) return 0;
    int target = (sum + S) / 2;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= nums[i-1]; j--) {
            dp[j] += dp[j - nums[i-1]];
        }
    }

    return dp[target];
}
