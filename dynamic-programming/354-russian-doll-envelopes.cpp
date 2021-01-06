// ID: 354
// Title: Russian Doll Envelopes
// Type: Dynamic Programming
// Difficulty: Hard
// URL: https://leetcode.com/problems/russian-doll-envelopes/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxEnvelopes(vector<vector<int>>& envelopes);

int main() {
    vector<vector<int>> e = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    cout << maxEnvelopes(e) << endl;
}

// TODO: this passes the time limit but is quite slow (O(n^2)), optimize dp vector to use a faster search
int maxEnvelopes(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;

    // sort first by width, then by height
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });
    
    int n = envelopes.size(), max_envs = 1;
    // dp stores the max # envelopes the i-th envelope can fit
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
                max_envs = max(max_envs, dp[i]);
            }
        }
    }

    return max_envs;
}
