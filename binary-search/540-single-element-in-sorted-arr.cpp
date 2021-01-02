// ID: 540
// Title: Single Element in a Sorted Array
// Type: Binary Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums);

int main() {
    vector<int> in = {1, 1, 2, 2, 3, 4, 4, 8, 8};
    cout << singleNonDuplicate(in) << endl;

    return 0;
}

int singleNonDuplicate(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];   // special case

    int l = 0, r = nums.size() - 1, m;

    while (l < r) {
        int m = (l + r) / 2;

        if (m != 0 && nums[m] == nums[m-1]) {         // mid value equals to the value to the left
            if (m % 2 == 1) l = m + 1;                    // m is odd, left half does not contain target
            else            r = m - 2;                    // m is even, left half contains target
        } else if (m != nums.size() - 1 && nums[m] == nums[m+1]) {
            if (m % 2 == 1) r = m - 1;
            else            l = m + 2;
        } else {
            return nums[m];
        }
    }

    return (l < 0) ? nums[r] : nums[l];
}
