#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (find(board, m, n, i, j, word, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool find(vector<vector<char>>& board, int& m, int& n, int row, int col, string& word, int i) {
        if (row < 0 || row >= m || col < 0 || col >= n || i >= word.size()) {
            return false;
        }
        if (board[row][col] == word[i]) {
            if (i == word.size() - 1) {
                return true;
            }
            board[row][col] = '#';
            if (find(board, m, n, row + 1, col, word, i + 1)) {
                return true;
            }
            if (find(board, m, n, row - 1, col, word, i + 1)) {
                return true;
            }
            if (find(board, m, n, row, col + 1, word, i + 1)) {
                return true;
            }
            if (find(board, m, n, row, col - 1, word, i + 1)) {
                return true;
            }
            board[row][col] = word[i];
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board = { {'a','a'} };
    string word = "aaa";
    cout << Solution().exist(board, word) << endl;
    return 0;
}