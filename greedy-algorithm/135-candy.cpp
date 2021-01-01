// ID: 135
// Title: Candy
// Type: Greedy Algorithm
// Difficulty: Hard
// URL: https://leetcode.com/problems/candy/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <iterator>

using namespace std;

int candy(vector<int>& ratings);

int main() {
    vector<int> r = {1, 2, 2};
    cout << candy(r) << endl;

    return 0;
}


int candy(vector<int>& ratings) {
    int size = ratings.size();
    if (size < 2) return size;
    
    vector<int> num(size, 1);
    
    // iterate from left to right, if right-rating > left_rating, right_candy = left_candy + 1,
    // this iteration only changes the relationship of any child with its left neighbour
    for (int i = 1; i < size; i++) {
        if (ratings[i] > ratings[i-1]) num[i] = num[i-1] + 1;
    }
    
    // similar iteration from right to left,
    // this iteration only changes the relationship of any child with its right neighbour
    for (int i = size - 1; i > 0; i--) {
        if (ratings[i] < ratings[i-1]) num[i-1] = max(num[i-1], num[i] + 1);
    }
    
    return accumulate(num.begin(), num.end(), 0);
}
