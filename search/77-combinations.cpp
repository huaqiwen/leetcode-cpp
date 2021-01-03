// ID: 77
// Title: Combinations
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/combinations/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> combine(int n, int k);
void backtrack(vector<vector<int>>& res, vector<int>& comb, int& count, int pos, int n, int k);

int main() {
    for (vector<int>& out : combine(4, 2)) {
        for (int& n : out) cout << n << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> comb(k, 0);
    int count = 0;
    backtrack(res, comb, count, 1, n, k);
    return res;
}

void backtrack(vector<vector<int>>& res, vector<int>& comb, int& count, int pos, int n, int k) {
    if (count == k) {
        res.push_back(comb);
        return;
    }
    for (int i = pos; i <= n; i++) {
        comb[count++] = i;          // modify current node's state
        backtrack(res, comb, count, i + 1, n, k);
        count--;                    // restore current node's state
    }
}