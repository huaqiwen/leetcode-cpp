// ID: 695
// Title: Max Area of Island
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/max-area-of-island/

#include <iostream>
#include <vector>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid);
int dfs(vector<vector<int>>& grid, int r, int c);

int main() {
    vector<vector<int>> in = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                              {0,1,1,0,1,0,0,0,0,0,0,0,0},
                              {0,1,0,0,1,1,0,0,1,0,1,0,0},
                              {0,1,0,0,1,1,0,0,1,1,1,0,0},
                              {0,0,0,0,0,0,0,0,0,0,1,0,0},
                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                              {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    cout << maxAreaOfIsland(in) << endl;
    
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) return 0;

    int max_area = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) max_area = max(max_area, dfs(grid, i, j));
        }
    }
    return max_area;
}

int dfs(vector<vector<int>>& grid, int r, int c) {
    if (grid[r][c] == 0) return 0;

    // every two consecutive elements of directions are one of the direction that we search
    vector<int> direction{-1, 0, 1, 0, -1};

    grid[r][c] = 0;
    int x, y, area = 1;
    for (int i = 0; i < 4; i++) {
        x = r + direction[i], y = c + direction[i+1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            area += dfs(grid, x, y);
    }

    return area;
}
