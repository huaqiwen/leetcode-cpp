// ID: 91
// Title: Decode Ways
// Type: Dynamic Programming
// Difficulty: Medium
// URL: https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s);

int main() {
    cout << numDecodings("226") << endl;
    cout << numDecodings("227") << endl;
}

int numDecodings(string s) {
    int n = s.size();
    if (!n) return 0;

    // pre1: # ways to decode the string 1 digit before curr
    // pre2: # ways to decode the string 2 digit before curr
    int pre1 = 1, pre2 = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        curr = 0;
        // curr digit != '0', can be decoded as a single digit #
        if (s[i] != '0') {
            curr += pre1;
        }
        // curr digit and the digit immediate left forms an integer within [10, 26], can be decoded as a double digit #
        if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) {
            curr += pre2;
        }
        pre2 = pre1;
        pre1 = curr;
    }
    return curr;
}
