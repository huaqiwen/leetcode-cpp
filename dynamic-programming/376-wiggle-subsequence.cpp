// ID: 376
// Title: Wiggle Subsequence
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/wiggle-subsequence/

#include <iostream>
#include <vector>

using namespace std;

int wiggleMaxLength(vector<int>& nums);

int main() {
    vector<int> in = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << wiggleMaxLength(in) << endl;
}

int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return n;

    // dp[i] stores the longest wiggle subsequence in nums[:i+1]
    vector<vector<int>> dp;
    for (int i = 0; i < n; i++)
        dp.push_back({nums[i]});

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (dp[j].size() < 2) {                                             // dp[j].size() == 1
                vector<int> temp = {dp[j][0], nums[i]};
                vector<int> new_seq = (nums[i] == dp[j][0]) ? dp[j] : temp;
                if (new_seq.size() > dp[i].size()) dp[i] = new_seq;
            } else {                                                            // dp[j].size() >= 2
                int j_size = dp[j].size();
                // if the last two elements from dp[j] is increasing, we need nums[i] < dp[j][-1], and vise versa 
                bool is_increasing = dp[j][j_size - 1] > dp[j][j_size - 2];
                if ((is_increasing && nums[i] >= dp[j][j_size - 1]) || (!is_increasing && nums[i] <= dp[j][j_size - 1]))
                    continue;
                
                // construct a new sequence by appending nums[i] to dp[j], modify dp[i] if the new sequence is longer
                vector<int> new_seq = dp[j];
                new_seq.push_back(nums[i]);
                if (new_seq.size() > dp[i].size()) dp[i] = new_seq;
            }
        }
    }

    return dp[n-1].size();
}
