// ID: 416
// Title: Partition Equal Subset Sum
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums);

int main() {
    vector<int> in = {1, 5, 11, 5};
    cout << canPartition(in) << endl;
}

bool canPartition(vector<int>& nums) {
    int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    
    int target = sum / 2;
    // This is similar to a regular 0-1 Knapsack Problem but we don't care about the value.
    // Here dp[i] will store whether i can be the sum of elements from the input array.
    vector<int> dp(target + 1, false); dp[0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = target; j >= nums[i - 1]; j--) {
            dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }

    return dp[target];
}
