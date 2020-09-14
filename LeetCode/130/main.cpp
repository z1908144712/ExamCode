#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3)
            return;
        
        for (int i = 0; i < board.size(); i++) {
            //左边界
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            //右边界
            if (board[i][board[i].size() - 1] == 'O')
                dfs(board, i, board[i].size() - 1);
        }
        for (int j = 1; j < board[0].size() - 1; j++) {
            //上边界
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            //下边界
            if (board[board.size() - 1][j] == 'O')
                dfs(board, board.size() - 1, j);
        }
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] == 'X' || board[i][j] == '#')
            return;
        board[i][j] = '#';
        dfs(board, i - 1, j); //上
        dfs(board, i + 1, j); //下
        dfs(board, i, j - 1); //左
        dfs(board, i, j + 1); //右
    }
};

int main() {
    Solution s;
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
    s.solve(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}