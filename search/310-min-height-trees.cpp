// ID: 310
// Title: Minimum Height Trees
// Type: Search
// Difficulty: Medium
// URL: https://leetcode.com/problems/minimum-height-trees/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges);

int main() {
    vector<vector<int>> in = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    for (int root : findMinHeightTrees(6, in))
        cout << root << " ";
    cout << endl;
}

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0};

    unordered_map<int, unordered_set<int>> adj;
    for (vector<int>& edge : edges) {
        adj[edge[0]].insert(edge[1]);
        adj[edge[1]].insert(edge[0]);
    }
    queue<int> leaves;
    for (auto& record : adj)
        if (record.second.size() == 1) leaves.push(record.first);

    // The roots of any MHTs are the middle point of the longest paths in the graph,
    // thus we remove leaf nodes one layer at a time until we have <= 2 nodes.
    // This way, as the speed of the pointers of the leaf nodes moving towards the center is the same, 
    // we obtains the center node(s) when the pointers meet.
    while (n > 2) {
        int leaves_size = leaves.size();
        n -= leaves_size;
        while (leaves_size--) {
            int leaf = leaves.front(); leaves.pop();
            for (int neighbour : adj[leaf]) {
                adj[neighbour].erase(leaf);
                if (adj[neighbour].size() == 1) leaves.push(neighbour);
            }
        }
    }

    vector<int> res;
    while (!leaves.empty()) {
        res.push_back(leaves.front());
        leaves.pop();
    } 
    return res;
}
