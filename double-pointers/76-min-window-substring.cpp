// ID: 76
// Title: Minimum Windows Substring
// Type: Two Pointers
// Difficulty: Hard
// URL: https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string minWindow(string s, string t);

int main() {
    cout << "\"" << minWindow("ADOBECODEBANC", "ABC") << "\"" << endl;

    return 0;
}

string minWindow(string s, string t) {
    // the indices of the two vectors represent characters (ascii code)
    vector<int> chars(128, 0);          // represents how many chars are missing (w.r.t to the index)
    vector<bool> flag(128, false);      // represents whether or not the char denoted by the index exists in `t`

    // init vectors `chars` and `flag`
    for (char& c : t) {
        flag[c] = true;
        chars[c]++;
    }

    int count = 0;                      // represents the number of satisfied chars in `t`
    int l = 0, min_l = 0, min_size = s.size() + 1;

    for (int r = 0; r < s.size(); r++) {
        if (flag[s[r]]) {
            if (--chars[s[r]] >= 0) count++;    // if right_ptr points to a missing char, increment count

            while (count == t.size()) {         // we have a desirable window
                // found a smaller window, update smallest window
                if (r - l + 1 < min_size) {
                    min_l = l;
                    min_size = r - l + 1;
                }
                // moving left_ptr to the right causes the windows to become undesirable, decrement count
                if (flag[s[l]] && ++chars[s[l]] > 0) count--;   
                // move left_ptr right a char
                l++;
            }
        }
    }

    return min_size > s.size() ? "" : s.substr(min_l, min_size);
}
