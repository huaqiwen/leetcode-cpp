// ID: 241
// Title: Different Ways to Add Parentheses
// Type: Divide and Conquer
// Difficulty: Medium
// URL: https://leetcode.com/problems/different-ways-to-add-parentheses/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> diffWaysToCompute(string input);

int main() {
    vector<int> out = diffWaysToCompute("2*3-4*5");
    for (int ans : out)
        cout << ans << " ";
    cout << endl;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> ways;

    for (int i = 0; i < input.size(); i++) {
        char c = input[i];

        if (isdigit(c)) continue;

        // if c is an operation, find diffWaysToCompute for both sides, then merge results
        // TODO: some of the results are been calculated more than once, try using memoization or dp
        vector<int> l_res = diffWaysToCompute(input.substr(0, i));
        vector<int> r_res = diffWaysToCompute(input.substr(i + 1));

        for (const int l : l_res) {
            for (const int r : r_res) {
                switch (c) {
                    case '+': ways.push_back(l + r); break;
                    case '-': ways.push_back(l - r); break;
                    case '*': ways.push_back(l * r); break;
                }
            }
        }
    }

    // the input is just an number, thus ways is empty
    if (ways.empty())
        ways.push_back(stoi(input));
    
    return ways;
}
