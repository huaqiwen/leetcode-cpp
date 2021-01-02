// ID: 347
// Title: Top K Frequent Elements
// Type: Sorting
// Difficulty: Medium
// URL: https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k);

int main() {
    vector<int> in = {1, 2};
    vector<int> out = topKFrequent(in, 2);
    for (int& o : out)
        cout << o << endl;
    
    return 0;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    // we will use bucket sort (create a bucket for each value that records the # occurences (or other properties),
    // then sort the buckets)

    unordered_map<int, int> counts;
    int max_count = 0;
    for(int& num : nums)
        max_count = max(max_count, ++counts[num]);
    
    // for all i, buckets[i] contains the numbers that occurs i times
    vector<vector<int>> buckets(max_count + 1);
    for(auto& count : counts) {
        buckets[count.second].push_back(count.first);
    }

    // we want k items from the last few buckets
    vector<int> res;
    for (int i = max_count; i >= 0 && res.size() < k; i--) {
        for (int& n : buckets[i]) {
            res.push_back(n);
            if (res.size() == k) break;
        }
    }

    return res;
}
