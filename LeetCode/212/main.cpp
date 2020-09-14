#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    class Trie {
    public:
        string word = "";
        map<char, Trie*> mp;
        Trie(){}
    };
    vector<string> r;
    int cols, rows;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows == 0 ? 0 : board[0].size();
        if (rows == 0 || cols == 0) {
            return r;
        }
        Trie* root = new Trie();
        for (string word : words) {
            Trie* cur = root;
            for (int i = 0; i < word.size(); i++) {
                if (cur->mp.count(word[i]) == 0) {
                    cur->mp.insert(make_pair(word[i], new Trie()));
                } 
                cur = cur->mp.at(word[i]);
            }
            cur->word = word;
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(board, root, i, j);
            }
        }
        return r;
    }

    void dfs(vector<vector<char>>& board, Trie *root, int x, int y) {
        char c = board[x][y];
        if (c == '.' || root->mp.count(c) == 0) {
            return;
        }
        root = root->mp.at(c);
        if (root->word.compare("") != 0) {
            r.push_back(root->word);
            root->word = "";
        }
        board[x][y] = '.';
        if (x > 0) {
            dfs(board, root, x - 1, y);
        }
        if (y > 0) {
            dfs(board, root, x, y - 1);
        }
        if (x + 1 < rows) {
            dfs(board, root, x + 1, y);
        }
        if (y + 1 < cols) {
            dfs(board, root, x, y + 1);
        }
        board[x][y] = c;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = { 
        {'o','a','a','n'} ,
        {'e','t','a','e' },
        {'i','h','k','r' },
        {'i','f','l','v' }
    };
    vector<string> words = { "oath","pea","eat","rain" };
    vector<string> r = sol.findWords(board, words);
    for (string s : r) {
        cout << s << " ";
    }
    return 0;
}