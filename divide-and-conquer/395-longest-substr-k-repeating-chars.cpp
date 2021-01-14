// ID: 395
// Title: Longest Substring with At Least K Repeating Characters
// Type: Divide and Conquer
// Difficulty: Medium
// URL: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestSubstring(string s, int k);

int main() {
    cout << longestSubstring("ababbc", 2) << endl;
}

int longestSubstring(string s, int k) {
    int n = s.size();
    
    if (n < k)
        return 0;
    
    // store counst of the 26 letters
    vector<int> count(26, 0);
    for (const char& c : s)
        count[c - 'a']++;

    // iterate all chars, if any char doesn't meet the condition (count >= k),
    // split at that position and solve the 2 substrings
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] >= k)
            continue;

        int l_max = (i > 0) ? longestSubstring(s.substr(0, i), k) : 0;
        int r_max = (i < n - 1) ? longestSubstring(s.substr(i + 1), k) : 0;
        return max(l_max, r_max);
    }

    // all chars in s occurs >= k times, (otherwise the above loop would return), return s size
    return n;
}
