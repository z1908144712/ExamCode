#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int i, j;
        for (i = 0; i < grid.size(); i++) {
            for (j = 0; j < grid[i].size(); j++) {
                if (i - 1 >= 0 && j - 1 >= 0) {
                    grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
                } else if (i - 1 >= 0) {
                    grid[i][j] += grid[i - 1][j];
                } else if (j - 1 >= 0) {
                    grid[i][j] += grid[i][j - 1];
                }
            }
        }
        return grid[i - 1][j - 1];
    }
};

int main() {
    vector<vector<int>> grid = { 
    {1,3,1},
    {1,5,1},
    {4,2,1}
    };
    cout << Solution().maxValue(grid) << endl;
    return 0;
}