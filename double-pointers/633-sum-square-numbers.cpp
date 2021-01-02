// ID: 633
// Title: Sum of Square Numbers
// Type: Two Pointers
// Difficulty: Medium
// URL: https://leetcode.com/problems/sum-of-square-numbers/

#include <iostream>
#include <cmath>

using namespace std;

bool judgeSquareSum(int c);

int main() {
    cout << (judgeSquareSum(5) ? "true" : "false") << endl;

    return 0;
}

bool judgeSquareSum(int c) {
    int l = 0, r = floor(sqrt(c));

    while (l <= r) {
        // comparing c^2 - b^2 with a^2 instead of a^2 + b^2 with c^2 to avoid integer overflow and using long long
        int lsqr = l * l, rsqr = r * r;
        if (c - lsqr == rsqr) return true;

        if (c - lsqr < rsqr) r--;
        else l++;
    }

    return false;
}
