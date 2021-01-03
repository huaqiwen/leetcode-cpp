// ID: 257
// Title: Binary Tree Paths
// Type: Search
// Difficulty: Easy
// URL: https://leetcode.com/problems/binary-tree-paths/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * @brief Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<string> binaryTreePaths(TreeNode* root);
void dfs(vector<string>& ans, TreeNode* curr, string& path);

int main() {
    TreeNode n1 = TreeNode(1);
    TreeNode n2 = TreeNode(2);
    TreeNode n3 = TreeNode(3);
    TreeNode n5 = TreeNode(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n5;

    for (string& path : binaryTreePaths(&n1))
        cout << path << endl;

    return 0;
}

vector<string> binaryTreePaths(TreeNode* root) {
    if (root == nullptr) return {};     // special case

    vector<string> ans;
    string path = "";
    dfs(ans, root, path);

    return ans;
}

void dfs(vector<string>& ans, TreeNode* curr, string& path) {
    path.append(to_string(curr->val));

    // no children => is a leaf node, append ans and return
    if (curr->left == nullptr && curr->right == nullptr) {
        ans.push_back(path);
        return;
    }

    // left path
    if (curr->left != nullptr) {
        string new_path = path + "->";
        dfs(ans, curr->left, new_path);
    }

    // right path
    if (curr->right != nullptr) {
        string new_path = path + "->";
        dfs(ans, curr->right, new_path);
    }
}
