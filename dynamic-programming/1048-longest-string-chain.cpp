// ID: 1048
// Title: Longest String Chain
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-string-chain/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int longestStrChain(vector<string>& words);

int main() {
    vector<string> in = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    cout << longestStrChain(in) << endl;
}

int longestStrChain(vector<string>& words) {
    int n = words.size();

    // sort words by length
    sort(words.begin(), words.end(), [](const string &s1, const string &s2) { 
        return s1.size() <s2.size(); 
    });
    
    // build map of predecessors
    vector<vector<int>> preds(n);

    for (int i = 0; i < n; i++) {
        // if the preceding string's size is less than curr string size -1, all prev strings can't be preds
        if (i > 0 && words[i-1].size() < words[i].size() - 1) continue;

        // iterate thru all prev strings
        for (int k = i - 1; k >= 0; k--) {
            // same size as curr string, can't be a pred
            if (words[k].size() == words[i].size()) continue; 

            for (int j = 0; j < words[i].size(); j++) {
                string w = words[i];
                w.erase(j, 1);

                string candidate = words[k];
                if (candidate.size() < w.size()) break;
                if (candidate == w) preds[i].push_back(k);
            }
        }
    }

    vector<int> dp(n, 1);   // denotes max len of any string chain ending at word[i]
    int max_len = 1;

    for (int i = 0; i < n; i++) {
        string curr = words[i];

        if (preds[i].size() == 0) {
            dp[i] = 1;
        } else {
            int max_pred_len = 1;
            for (int pred_i : preds[i]) {
                max_pred_len = max(max_pred_len, dp[pred_i]);
            }

            // dp[i] should be 1 + max of preds max len
            dp[i] = max_pred_len + 1;
            max_len = max(max_len, max_pred_len + 1);
        }
    }

    return max_len;
}
