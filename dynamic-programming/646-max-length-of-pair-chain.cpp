// ID: 646
// Title: Maximum Length of Pair Chain
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs);
int findLongestChainDP(vector<vector<int>>& pairs);

int main() {
    vector<vector<int>> in = {{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> inr = {{3, 4}, {2, 3}, {1, 2}};
    cout << findLongestChain(in) << endl;
    cout << findLongestChain(inr) << endl;
}

// TODO: this is greedy and costs O(nlogn), use dp for a possible O(n) solution
int findLongestChain(vector<vector<int>>& pairs) {
    // we first sort the pairs by their ENDs, then for all consecutive pairs, we have 1 of 3 cases:
    // 1. s1 < e1 < s2 < e2
    // 2. s1 < s2 < e1 < e2
    // 3. s2 < s1 < e1 < e2
    // among the 3, we increment counter only iff we have condition 1
    sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });

    int curr_back = INT32_MIN, count = 0;
    for (vector<int>& pair : pairs) {
        if (curr_back < pair[0]) {              // cond 1 is met
            curr_back = pair[1]; count++;
        }
    }

    return count;
}
