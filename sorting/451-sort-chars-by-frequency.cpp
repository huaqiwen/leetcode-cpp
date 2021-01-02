// ID: 451
// Title: Sort Characters By Frequency
// Type: Sorting
// Difficulty: Medium
// URL: https://leetcode.com/problems/sort-characters-by-frequency/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string frequencySort(string s);

int main() {
    cout << frequencySort("tree") << endl;
    cout << frequencySort("Aabb") << endl;

    return 0;
}

string frequencySort(string s) {
    // this question is similar to 347; use bucket sort

    unordered_map<char, int> counts;
    int max_count = 0;
    for(char& c : s)
        max_count = max(max_count, ++counts[c]);

    vector<vector<char>> buckets(max_count + 1);
    for (auto& count : counts)
        buckets[count.second].push_back(count.first);

    string res = "";
    for (int i = max_count; i > 0; i--) {
        for (char& c : buckets[i])
            for (int j = 0; j < i; j++) res.push_back(c);           // push back char `c` i times
    }

    return res;
}
