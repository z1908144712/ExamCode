#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    r++;
                    visit(grid, i, j);
                }
            }
        }
        return r;
    }

    void visit(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) {
            return;
        }
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
        } else {
            return;
        }
        visit(grid, i - 1, j);
        visit(grid, i + 1, j);
        visit(grid, i, j - 1);
        visit(grid, i, j + 1);
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = { {'1', '1', '0', '0', '0'},{'1', '1', '0', '0', '0'},{'0', '0', '1', '0', '0'},{'0', '0', '0', '1', '1'} };
    cout << sol.numIslands(grid) << endl;
    return 0;
}