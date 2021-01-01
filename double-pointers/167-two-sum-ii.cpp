// ID: 167
// Title: Two Sum II - Input array is sorted
// Type: Two Pointers
// Difficulty: Easy
// URL: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target);

int main() {
    vector<int> inv = {2, 7, 11, 15};
    vector<int> ans = twoSum(inv, 9);
    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}


vector<int> twoSum(vector<int>& numbers, int target) {
    int lp = 0, rp = numbers.size() - 1;

    while (lp < rp) {
        int s = numbers[lp] + numbers[rp];
        // answers found
        if (s == target) return {lp + 1, rp + 1};

        // sum too big ? move left pointer right 1 step : move right pointer left 1 step
        if (s > target) rp--; else lp++;
    }

    return {-1, -1};
}
