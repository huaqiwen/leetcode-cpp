// ID: 763
// Title: Partition Labels
// Type: Greedy Algorithm
// Difficulty: Medium
// URL: https://leetcode.com/problems/partition-labels/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <iterator>

using namespace std;

vector<int> partitionLabels(string S);

int main() {
    vector<int> lengths = partitionLabels("ababcbacadefegdehijhklij");
    for (int& l : lengths)
        cout << l << " ";
    cout << endl;

    return 0;
}


vector<int> partitionLabels(string S) {
    vector<int> res;                // vector of partition lengths
    unordered_map<char, int> m;     // key: possible char in S, 
                                    // value: index of the partition that contains the key char 

    for (char& c : S) {
        if (m.find(c) == m.end()) {
            // curr char is not in map:

            res.push_back(1);           // new partition
            m[c] = res.size() - 1;      // save the index of the partition that contains the curr char
        } else {
            // curr char is in map:

            int idx = m[c];
            // new partition length
            int ptLen = accumulate(res.begin() + idx, res.end(), 0) + 1;

            // remove the last few partitions, keeping only the first m[c] partitions, push ptLen
            res = vector<int>(res.begin(), res.begin() + idx);
            res.push_back(ptLen);

            // update map
            for (auto& pair : m) {
                if (pair.second > idx) m[pair.first] = idx; 
            }
        }
    }

    return res;
}
