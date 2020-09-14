#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        if (size <= 1) {
            return size;
        }
        int up = 0;
        int down = 0;
        int candies = 0;
        int old_slope = 0;
        for (int i = 1; i < size; i++) {
            int new_slope = (ratings[i] > ratings[i - 1]) ? 1 : ((ratings[i] < ratings[i - 1]) ? -1 : 0);
            if ((old_slope > 0 && new_slope == 0) || (old_slope < 0 && new_slope >=0)) {
                candies += count(up) + count(down) + max(up, down);
                down = up = 0;
            }
            if (new_slope == 1) {
                up++;
            } else if (new_slope == -1) {
                down++;
            } else if (new_slope == 0) {
                candies++;
            }
            old_slope = new_slope;
        }
        candies += count(up) + count(down) + max(up, down) + 1;
        return candies;
    }

    int count(int n) {
        return (n * (n + 1)) / 2;
    }
};

int main() {
    vector<int> ratings = { 1,0,2 };
    Solution sol;
    cout << sol.candy(ratings) << endl;
}