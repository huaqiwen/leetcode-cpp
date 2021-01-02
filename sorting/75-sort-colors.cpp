// ID: 75
// Title: Sort Colors
// Type: Sorting
// Difficulty: Medium
// URL: https://leetcode.com/problems/sort-colors/

#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums);

int main() {
    vector<int> in = {2, 0, 2, 1, 1, 0, 0};
    sortColors(in);
    for (int& n : in) 
        cout << n << " ";
    cout << endl;

    return 0;
}

void sortColors(vector<int>& nums) {
    // for all i, counts[i] is the # occurences of i in nums
    vector<int> counts(3, 0);
    for (int& n : nums)
        counts[n]++;
    
    // modify input array according to `counts`
    int ptr = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < counts[i]; j++)
            nums[++ptr] = i;
    }
}
