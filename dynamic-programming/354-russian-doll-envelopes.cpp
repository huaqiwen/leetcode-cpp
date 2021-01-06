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
int maxEnvelopes2(vector<vector<int>>& envelopes);

int main() {
    vector<vector<int>> e = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
    cout << maxEnvelopes2(e) << endl;
}

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

// This method takes only O(nlogn). 
// The sorting of the input enveloeps simplifies this question to a 1D LIS problem (no.300).
int maxEnvelopes2(vector<vector<int>>& envelopes) {
    if (envelopes.empty()) return 0;

    // sort first by width (increasing order), then by height (decreasing order)
    sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    int n = envelopes.size();
    vector<int> dp = {envelopes[0][1]};

    for (int i = 1; i < n; i++) {
        // we can use only height because: 1. the current width must >= all previous widths
        //                                 2. as we sorted the subsequence w/ same widths in decreasing order, if
        //                                    the current width > previous width, we know the current height must
        //                                    > previous height as well 
        if (envelopes[i][1] > dp.back()) {
            dp.push_back(envelopes[i][1]);
        } else {
            auto it = lower_bound(dp.begin(), dp.end(), envelopes[i][1]);
            *it = envelopes[i][1];
        }
    }

    return dp.size();
}
