#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> r;
        int m = matrix.size();
        if (m == 0) {
            return r;
        }
        int n = matrix[0].size();
        if (n == 0) {
            return r;
        }
        int row = 0, col = 0, row_left = 0, row_right = m - 1, col_left = 0, col_right = n - 1;
        bool move_left = false, move_right = true, move_up = false, move_down = false;
        while (row <= row_right && row >= row_left && col <= col_right && col >= col_left) {
            r.push_back(matrix[row][col]);
            if (move_right) {
                col++;
                if (col > col_right) {
                    move_right = false;
                    move_down = true;
                    col = col_right;
                    row_left++;
                    row = row_left;
                }
            } else if (move_left) {
                col--;
                if (col < col_left) {
                    move_left = false;
                    move_up = true;
                    col = col_left;
                    row_right--;
                    row = row_right;
                }
            } else if (move_down) {
                row++;
                if (row > row_right) {
                    move_down = false;
                    move_left = true;
                    row = row_right;
                    col_right--;
                    col = col_right;
                }
            } else if (move_up) {
                row--;
                if (row < row_left) {
                    move_up = false;
                    move_right = true;
                    row = row_left;
                    col_left++;
                    col = col_left;
                }
            }
        }
        return r;
    }
};

int main() {
    vector<vector<int>> matrix = { {1,2,3,4} ,{5,6,7,8},{9,10,11,12} };
    vector<int> r = Solution().spiralOrder(matrix);
    for (auto& i : r) {
        cout << i << " ";
    }
    return 0;
}