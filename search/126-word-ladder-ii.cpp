// ID: 126
// Title: Word Ladder II
// Type: Search
// Difficulty: Hard
// URL: https://leetcode.com/problems/word-ladder-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
void backtrack(vector<vector<string>>& ans, vector<string>& path, string curr, string target, unordered_map<string, vector<string>>& m);

int main() {
    vector<string> dictIn = {"hot","dot","dog","lot","log","cog"};
    for (vector<string>& path : findLadders("hit", "cog", dictIn)) {
        for (string& word : path) 
            cout << word << " ";
        cout << endl;
    }

    return 0;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    // convert wordList to unordered_set for easier removal
    unordered_set<string> dict;
    for (const string& w : wordList) dict.insert(w);
    if (!dict.count(endWord)) return {};

    // we do bfs from both startWord and endWord;
    // at each iteration, only expand the queue with the least nodes, 
    // this decreases the number of searched nodes 
    unordered_set<string> q1, q2;
    q1.insert(beginWord); q2.insert(endWord);
    dict.erase(endWord); dict.erase(endWord);

    unordered_map<string, vector<string>> adj;
    bool reversed = false, found = false;

    while(!q1.empty()) {
        unordered_set<string> q;

        for (const string& curr : q1) {
            // find all connected words and push them into queue
            string s = curr;
            for (size_t i = 0; i < s.size(); i++) {
                char temp = s[i];
                for (char x = 'a'; x <= 'z'; x++) {
                    s[i] = x;                   // s is 1 char diff from curr
                    if (q2.count(s)) {          // new word found in q2, i.e., two-way bfs met each other, path found
                        reversed ? adj[s].push_back(curr) : adj[curr].push_back(s);
                        found = true;
                    }
                    if (dict.count(s)) {        // new word not in q2 but in dictionary, add to queue
                        reversed ? adj[s].push_back(curr) : adj[curr].push_back(s);
                        q.insert(s);
                    }
                }
                s[i] = temp;                    // restore s
            }
        }
        if (found) break;

        // The loop above adds one *layer* of iterations in the graph, remove the nodes added
        // so that the "child nodes" of each nodes in `adj` contains only outter layer nodes.  
        for (const string& w : q) dict.erase(w);

        // Make q1 the queue with the smallest # nodes. 
        if (q.size() <= q2.size()) {
            q1 = q;
        } else {
            reversed = !reversed;
            q1 = q2; q2 = q;
        }
    }

    // dfs to find all paths with `steps` steps
    vector<vector<string>> ans; {
        vector<string> init_path = {beginWord};
        backtrack(ans, init_path, beginWord, endWord, adj);
    }
    return ans;
}

void backtrack(vector<vector<string>>& ans, vector<string>& path, string curr, string target, unordered_map<string, vector<string>>& m) {
    if (curr == target) {
        if (!count(ans.begin(), ans.end(), path))
            ans.push_back(path);
        return;
    }

    for (const string& w : m[curr]) {
        path.push_back(w);
        backtrack(ans, path, w, target, m);
        path.pop_back();
    }
}
