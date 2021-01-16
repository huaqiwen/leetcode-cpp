// ID: 769
// Title: Max Chunks To Make Sorted
// Type: Others
// Difficulty: Medium
// URL: https://leetcode.com/problems/max-chunks-to-make-sorted/

#include <iostream>
#include <vector>

using namespace std;

int maxChunksToSorted(vector<int>& arr);

int main() {
    vector<int> in = {1, 0, 3, 2, 4};
    cout << maxChunksToSorted(in) << endl;
}

int maxChunksToSorted(vector<int>& arr) {
    // curr_chunk_end denotes the minimum ending idx of the current chunk
    int curr_chunk_end = 0, chunks = 0;

    for (int i = 0; i < arr.size(); i++) {
        // the number in arr[i] makes the current chunk end at least after i
        curr_chunk_end = max(curr_chunk_end, arr[i]);

        if (i == curr_chunk_end)
            chunks ++;
    }

    return chunks;
}
