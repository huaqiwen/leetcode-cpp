// ID: 81
// Title: Search in Rotated Sorted Array II
// Type: Binary Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target);

int main() {
    vector<int> in = {2, 5, 6, 0, 0, 1, 2};
    cout << (search(in, 0) ? "true" : "false") << endl;
    cout << (search(in, 3) ? "true" : "false") << endl;

    return 0;
}

bool search(vector<int>& nums, int target) {
    if (nums.size() == 0) return false;

    int l = 0, r = nums.size() - 1, m;

    while (l < r) {
        m = (l + r) / 2;
        if (nums[m] == target) return true;

        if (nums[m] < nums[r]) {            // mid value < last value, the right half is sorted
            if (nums[m] < target && target <= nums[r]) {        // target is in the range of right half
                l = m + 1;
            } else {
                r = m - 1;
            }
        } else if (nums[m] > nums[r]) {     // mid value > last value, the left half is sorted
            if (nums[l] <= target && target < nums[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        } else {                                // mid value = last value, move right_ptr left 1 bit
            r--;
        }
    }

    return nums[l] == target;
}
