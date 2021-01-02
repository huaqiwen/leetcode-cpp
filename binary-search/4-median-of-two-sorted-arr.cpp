// ID: 4
// Title: Median of Two Sorted Arrays
// Type: Binary Search
// Difficulty: Hard
// URL: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

int main() {
    vector<int> in1 = {1, 2};
    vector<int> in2 = {3, 4};
    cout << findMedianSortedArrays(in1, in2) << endl;

    in1 = {1, 3}; in2 = {2};
    cout << findMedianSortedArrays(in1, in2) << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size(), n2 = nums2.size();

    // want to assume n1 <= n2
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
    
    int k = (n1 + n2 + 1) / 2;              // k - 1 is the index of the median of the merged arr (or the left median)
    int l = 0, r = n1;

    // The goal is after loop terminates, nums1[m1] > nums2[m2-1] and nums2[m2] > nums1[m1-1]) (overlap),
    // thus all first m1 elements of nums1 are smaller than the [m2:] elements of nums2, and vise versa.
    // Then nums1[m1-1] and nums2[m2-1] are the two candidates for the left median, and
    // nums1[m1] and nums2[m2] are the two candidates for the right median.
    while (l < r) {
        int m1 = (l + r) / 2, m2 = k - m1;
        if (nums1[m1] < nums2[m2 - 1])
            l = m1 + 1;
        else
            r = m1; 
    }

    // take m1 elements from nums1, m2 elements from nums2 to form the first k elements of the merged arr
    int m1 = l, m2 = k - l;
    int c1 = max(m1 <= 0 ? INT32_MIN : nums1[m1-1], m2 <= 0 ? INT32_MIN : nums2[m2 - 1]);   // left median
    if ((n1 + n2) % 2 == 1) return c1;

    int c2 = min(m1 >= n1 ? INT32_MAX : nums1[m1], m2 >= n2 ? INT32_MAX : nums2[m2]);       // right median
    return (c1 + c2) * 0.5;
}
