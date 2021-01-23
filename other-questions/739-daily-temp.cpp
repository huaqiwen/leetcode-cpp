// ID: 739
// Title: Daily Temperatures
// Type: Others (Monotonic Stack)
// Difficulty: Medium
// URL: https://leetcode.com/problems/daily-temperatures/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T);

int main() {
    vector<int> in = {73, 74, 75, 71, 69, 72, 76, 73};
    for (int n : dailyTemperatures(in))
        cout << n << " ";
    cout << endl;
}

vector<int> dailyTemperatures(vector<int>& T) {
    int n = T.size();
    vector<int> ans(n, 0);
    stack<int> ms;

    /*
    Monotonic stack method:
        - The stack `ms` keeps dates (indices of T).
        - Iterate each date. At each iter, while the stack is non-empty, if the top of the 
          stack has a lower temp than curr temp, pop the stack and record answer for the popped
          date. 
        - When the top date has a higher temp than curr, break loop and push curr date in, as it 
          won't have higher temp than any prev dates
        * Note that temps represented by elems in `ms` are monotonic decreasing.
    */
    for (int i = 0; i < n; i++) {
        while (!ms.empty()) {
            int top_date = ms.top();
            if (T[top_date] > T[i]) break;

            ms.pop();
            ans[top_date] = i - top_date;
        }
        ms.push(i);
    }

    return ans;
}
