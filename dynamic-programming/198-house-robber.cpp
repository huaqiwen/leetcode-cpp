// ID: 198
// Title: House Robber
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/house-robber/

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums);

int main() {
    vector<int> in = {2, 7, 9, 3, 1};
    cout << rob(in) << endl;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (!n) return 0;
    if (n == 1) return nums[0];
    if (n == 2) return max(nums[0], nums[1]);

    // pre1: the cumulative max money when robber arrives the (i-1)th house
    // pre2: the cumulative max money when robber arrives the (i-2)th house
    int pre1 = max(nums[0], nums[1]), pre2 = nums[0], curr;
    for (int i = 2; i < n; i++) {
        // current max money = max(cumu money at (i-2)th house + robb current house, 
        //                         cumu money at (i-1)th house)
        curr = max(nums[i] + pre2, pre1);
        pre2 = pre1;
        pre1 = curr;
    }
    return curr;
}
