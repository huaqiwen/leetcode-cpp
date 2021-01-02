// ID: 215
// Title: Kth Largest Element in an Array
// Type: Sorting
// Difficulty: Medium
// URL: https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k);
int quickSelection(vector<int>& nums, int l, int r);

int main() {
    vector<int> in = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(in, 4) << endl;

    return 0;
}

int findKthLargest(vector<int>& nums, int k) {
    // this is similar to quick sort, except that we only need the k-th largest pivot,
    // i.e., we don't need to sort the left & right halfs 

    int l = 0, r = nums.size() - 1, target = nums.size() - k;
    while (l < r) {
        int mid = quickSelection(nums, l, r);           // mid is the index of a sorted pivot
        if (mid == target)
            return nums[mid];
        if (mid < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return nums[l];
}

/**
 * @brief puts the pivot (nums[l]) at the sorted position and returns its new index
 */
int quickSelection(vector<int>& nums, int l, int r) {
    // we take the first elem (l) as the pivot, init i, j
    int i = l + 1, j = r;

    while (true) {
        while (i < r && nums[i] <= nums[l])
            i++;
        while (l < j && nums[j] >= nums[l])
            j--;
        if (i >= j) 
            break;
        swap(nums[i], nums[j]);
    }
    swap(nums[l], nums[j]);
    return j;
}
