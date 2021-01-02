// ID: 154
// Title: Find Minimum in Rotated Sorted Array II
// Type: Binary Search
// Difficulty: Hard
// URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums);

int main() {
    vector<int> in1 = {4, 5, 6, 7, 0, 1, 2};
    vector<int> in2 = {2, 2, 2, 4, 1, 1};

    cout << findMin(in1) << endl;
    cout << findMin(in2) << endl;

    return 0;
}

int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, m;

    while (l < r) {
        m = (l + r) / 2;
        
        // check whether nums[m] is min
        int mLeft = (m == 0) ? r : m - 1;
        if (nums[m] < nums[mLeft]) return nums[m];

        if (nums[m] < nums[r]) {                // right half sorted, min in left half
            r = m - 1;
        } else if (nums[m] > nums[r]) {         // left half sorted while right half is NOT, min in right half
            l = m + 1;
        } else {                                // move right ptr left 1 bit
            r--;
        }
    }

    return nums[l];
}
