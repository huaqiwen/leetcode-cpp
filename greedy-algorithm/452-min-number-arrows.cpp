// ID: 452
// Title: Minimum Number of Arrows to Burst Balloons
// URL: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
// Type: Greedy Algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinArrowShots(vector<vector<int>>& points);

int main() {
    vector<vector<int>> pts = {{9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}};
    cout << findMinArrowShots(pts) << endl;

    return 0;
}


int findMinArrowShots(vector<vector<int>>& points) {
    int count = 1; int n = points.size();

    // points has no elems
    if (n == 0) return 0;

    // sort points by each x_start
    sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
    });
    
    // init prev that stores the previous end number
    int prev = points[0][1];

    for (int i = 1; i < n; i++) {
        if (points[i][0] > prev) {
            // current start is greater than prev end, need a new arrow, reset prev to curr_end
            count ++;
            prev = points[i][1];
        } else {
            // current start is leq prev end, no need for a new arrow, reset prev to be min(curr_end, prev)
            prev = min(points[i][1], prev);
        }
    }

    return count;
}
