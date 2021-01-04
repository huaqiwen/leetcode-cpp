// ID: 413
// Title: Arithmetic Slices
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/arithmetic-slices/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A);

int main() {
    vector<int> in = {1, 2, 3, 4};
    cout << numberOfArithmeticSlices(in) << endl;
}

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    // the dp vector stores the # arithmetic sequences that ends at A[i]
    vector<int> dp(n, 0);

    for (int i = 2; i < n; i++) {
        if (A[i] - A[i-1] == A[i-1] - A[i-2])
            // there is a new sequence (A[i-2], A[i-1], A[i]), and all sequences ended at A[i-1]
            dp[i] = dp[i-1] + 1;
    }

    return accumulate(dp.begin(), dp.end(), 0);
}
