// ID: 240
// Title: Search a 2D Matrix II
// Type: Others
// Difficulty: Medium
// URL: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target);

int main() {
    vector<vector<int>> m = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    cout << searchMatrix(m, 5) << endl;
    cout << searchMatrix(m, 20) << endl;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // start at top right corner
    int i = 0, j = matrix[0].size() - 1;

    while (i < matrix.size() && j >= 0) {
        int curr = matrix[i][j];
        if (curr == target) 
            return true;
        
        if (curr > target)      // curr > target implies all numbers under curr > target
            j--;         
        else                    // curr < target implies all numbers left of curr < target
            i++;
    }

    return false;
}
