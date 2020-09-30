#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row_flag = false, col_flag = false;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                col_flag = true;
                break;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (matrix[0][i] == 0) {
                row_flag = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[i].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }    
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            if (col_flag) {
                matrix[i][0] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++) {
            if (row_flag) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };
    Solution().setZeroes(matrix);
    for (auto &row : matrix) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
	return 0;
}