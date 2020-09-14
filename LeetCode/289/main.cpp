#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> copy_board = board;
        int m = copy_board.size(), n = copy_board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = 0;
                if (i - 1 >= 0 && copy_board[i - 1][j] == 1) {
                    count++;
                }
                if (i + 1 < m && copy_board[i + 1][j] == 1) {
                    count++;
                }
                if (j - 1 >= 0 && copy_board[i][j - 1] == 1) {
                    count++;
                }
                if (j + 1 < n && copy_board[i][j + 1] == 1) {
                    count++;
                }
                if (i - 1 >= 0 && j - 1 >= 0 && copy_board[i - 1][j - 1] == 1) {
                    count++;
                }
                if (i + 1 < m && j + 1 < n && copy_board[i + 1][j + 1] == 1) {
                    count++;
                }
                if (i + 1 < m && j - 1 >= 0 && copy_board[i + 1][j - 1] == 1) {
                    count++;
                }
                if (i - 1 >= 0 && j + 1 < n && copy_board[i - 1][j + 1] == 1) {
                    count++;
                }
                if ((count < 2 || count > 3) && board[i][j] == 1) {
                    board[i][j] = 0;
                }
                if (count == 3 && board[i][j] == 0) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    vector<vector<int>> board = {
        {0,1,0},
        {0,0,1},
        {1,1,1},
        {0,0,0}
    };
    Solution().gameOfLife(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}