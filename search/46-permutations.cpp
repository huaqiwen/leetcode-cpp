// ID: 46
// Title: Permutations
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums);
void backtrack(vector<int>& nums, int level, vector<vector<int>>& res);

int main() {
    vector<int> in = {1, 2, 3};
    for (vector<int>& out : permute(in)) {
        for (int& n : out) cout << n << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    backtrack(nums, 0, res);
    return res;
}


void backtrack(vector<int>& nums, int level, vector<vector<int>>& res) {
    if (level == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    for (int i = level; i < nums.size(); i++) {
        swap(nums[i], nums[level]);         // modifty current node's state
        backtrack(nums, level + 1, res);
        swap(nums[i], nums[level]);         // restore current node's state
    }
}
