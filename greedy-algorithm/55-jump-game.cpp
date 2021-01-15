// ID: 55
// Title: Jump Game
// Type: Greedy Algorithm
// Difficulty: Medium
// URL: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums);

int main() {
    vector<int> in1 = {2, 3, 1, 1, 4};
    vector<int> in2 = {3, 2, 1, 0, 4};
    cout << canJump(in1) << endl;
    cout << canJump(in2) << endl;
}

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int i = 0;

    while (i < n) {
        // can reach end position directly
        if (i + nums[i] + 1 >= n)
            return true;
        
        // curr at a dead position
        if (nums[i] == 0)
            return false;
        
        // next_step.first denotes the position of the best next jump (maximize distance)
        //          .second denotes the corresponding distance
        pair<int, int> next_step = {i, INT32_MIN};

        for (int s = 1; s <= nums[i]; s++) {
            // distance is calculated by [steps to reach the next pos] + [max step at the next pos]
            if (s + nums[i + s] > next_step.second)
                next_step = {i + s, s + nums[i + s]};
        }

        i = next_step.first;
    }

    return false;
}
