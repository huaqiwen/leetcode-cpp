// ID: 934
// Title: Shortest Bridge
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/shortest-bridge/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestBridge(vector<vector<int>>& A);
void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q);

vector<int> direction = {-1, 0, 1, 0, -1};

int main() {
    vector<vector<int>> in = {{0, 1, 0},
                              {0, 0, 0},
                              {0, 0, 1}};
    cout << shortestBridge(in) << endl;

    return 0;
}

int shortestBridge(vector<vector<int>>& A) {
    int m = A.size(), n = A[0].size();
    queue<pair<int, int>> q;                // the queue stores all (x, y) coordinates of the first island
    bool found_first_island = false;
    
    // dfs to find the first island, push all lands (starting points) to queue, and mark the island as 2's
    for (int i = 0; i < m && !found_first_island; i++) {
        for (int j = 0; j < n && !found_first_island; j++) {
            if (A[i][j] == 1) {
                dfs(A, j, i, q);
                found_first_island = true;
            }
        }
    }

    // bfs to search for a path to the other island (marked as 1's)
    int steps = 0;
    while (!q.empty()) {
        int q_size = q.size();
        while (q_size--) {                  // each item (starting point) in queue should expand 1 step
            int x = q.front().first, y = q.front().second; q.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = x + direction[i], new_y = y + direction[i+1];
                if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || A[new_y][new_x] == 2)
                    continue;
                if (A[new_y][new_x] == 1)       // second island found, return steps
                    return steps;
                A[new_y][new_x] = 2;
                q.push({new_x, new_y});
            }
        }
        // every starting points in queue has expanded 1 step, increment steps counter
        steps++;
    }

    return -1;
}

/**
 * @brief Finds the island that contains A[y][x] (assuming A[y][x] == 1), pushes all lands of the island into 
 * the input queue and mark them as 2.
 */
void dfs(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
    if (x < 0 || x >= A[0].size() || y < 0 || y >= A.size() || A[y][x] != 1)
        return;
    A[y][x] = 2;
    q.push({x, y});
    
    for (int i = 0; i < 4; i++) {
        int new_x = x + direction[i], new_y = y + direction[i+1];
        dfs(A, new_x, new_y, q);
    }
}
