// ID: 605
// Title: Can Plance Flowers
// Type: Greedy Algorithm
// Difficulty: Easy
// URL: https://leetcode.com/problems/can-place-flowers/

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);

int main() {
    vector<int> fb = {1, 0, 0, 0, 1};
    cout << (canPlaceFlowers(fb, 2) ? "true" : "false") << endl;

    return 0;
}


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    flowerbed.push_back(0);
    
    bool prev = false;  // indicates whether previous slot can be planted
    int count = 0;      // max allowed plants
    
    for (int i = 0; i < flowerbed.size() - 1; i++) {
        if (!prev) {    // the one on the left has no plant
            if (flowerbed[i] == 0 && flowerbed[i+1] == 0)      // curr has not plant
                count++;
            prev = true;
        } else {
            prev = (flowerbed[i] == 1);
        }
    }
    
    return (n <= count);
}
