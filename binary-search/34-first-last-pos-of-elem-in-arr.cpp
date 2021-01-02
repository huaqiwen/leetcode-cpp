// ID: 34
// Title: Find First and Last Position of Element in Sorted Array
// Type: Binary Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target);
int lower_bound(vector<int>& nums, int target);
int upper_bound(vector<int>& nums, int target);

int main() {
    vector<int> in = {5, 7, 7, 8, 8, 10};
    vector<int> in2 = {2, 2};
    vector<int> out0 = searchRange(in, 8);
    vector<int> out1 = searchRange(in, 6);
    vector<int> out3 = searchRange(in2, 2);

    cout << out0[0] << ", " << out0[1] << endl;
    cout << out1[0] << ", " << out1[1] << endl;
    cout << out3[0] << ", " << out3[1] << endl;

    return 0;
}

vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) return {-1, -1};
    
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target);

    return {lower, upper};
}

// Returns the index of the first occurence of `target` in `nums`, -1 if no occurrence
int lower_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    
    while (l < r) {
        m = (r + l) / 2;
        // found target at m
        if (nums[m] == target) {
            // nums[m-1] also equals to target, this is not a lower bound
            if (m != 0 && nums[m-1] == target) r = m - 1; else return m;
        } 
        else if (nums[m] > target) r = m - 1; 
        else l = m + 1;
    }

    return (nums[l] == target) ? l : -1;
}

// Returns the index of the last occurence of `target` in `nums`, -1 if no occurrence
int upper_bound(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    
    while (l < r) {
        m = (r + l) / 2;
        // found target at m
        if (nums[m] == target) {
            // nums[m+1] also equals to target, this is not a upper bound
            if (m != nums.size() - 1 && nums[m+1] == target) l = m + 1; else return m;
        } 
        else if (nums[m] > target) r = m - 1; 
        else l = m + 1;
    }

    return (nums[l] == target) ? l : -1;
}
