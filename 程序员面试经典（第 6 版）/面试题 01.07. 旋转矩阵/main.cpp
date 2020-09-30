#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n/2; i++) {
            for (int j = i; j < n - i - 1; j++) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = t;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix{
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    Solution().rotate(matrix);
    for (auto &row : matrix) {
        for (auto &col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
	return 0;
}