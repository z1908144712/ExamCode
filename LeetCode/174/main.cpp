#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size(), min;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1] = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                min = dp[i][j + 1] < dp[i + 1][j] ? dp[i][j + 1] : dp[i + 1][j];
                min -= dungeon[i][j];
                dp[i][j] = 1 > min ? 1 : min;
            }
        }
        return dp[0][0];
    }
};

int main() {
    Solution sol;
    //vector<vector<int>> dungeon = { {1, -3, 3},{0, -2, 0},{-3, -3, -3} };
    //vector<vector<int>> dungeon = { {-2,-3,3},{-5,-10,1},{10,30,-5} };
    vector<vector<int>> dungeon = { {0,0}};
    //vector<vector<int>> dungeon = { {3, -20, 30},{-3, 4, 0} };
    //vector<vector<int>> dungeon = { {3, 0, -3},{-3, -2, -2},{3, 1, -3} };
    //vector<vector<int>> dungeon = { {0, 0, 0}, {-1, 0, 0},{2, 0, -2} };
    cout << sol.calculateMinimumHP(dungeon) << endl;
    return 0;
}

