#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
	size_t X_SUB = 1, X_ADD = 2, Y_SUB = 4, Y_ADD = 8, m, n;
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0 || word.size() == 0) {
			return false;
		}
		m = board.size();
		n = board[0].size();
		if (n == 0) {
			return false;
		}
		vector<vector<size_t>> indexs;
		for (size_t i = 0; i < board.size(); i++) {
			for (size_t j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					indexs.push_back({i, j});
				}
			}
		}
		vector<map<pair<size_t, size_t>, size_t>> stack;
 		for (size_t i = 0; i < indexs.size(); i++) {
			size_t x = indexs[i][0], y = indexs[i][1], w = getW(x, y);
			map<pair<size_t, size_t>, size_t> mp;
			mp[make_pair(x, y)] = w;
			stack.push_back(mp);
			size_t word_index = 1;
			while (stack.size() > 0 && word_index < word.size()) {
				x = stack.back().begin()->first.first;
				y = stack.back().begin()->first.second;
				w = stack.back().begin()->second;
				if ((w & X_SUB) == X_SUB && board[x-1][y] == word[word_index]) {
					stack.back().begin()->second ^= X_SUB;
					if (hasStack(stack, make_pair(size_t(x-1), y))) {
						continue;
					}
					x--;
					word_index++;
					w = getW(x, y) ^ X_ADD;
					mp.clear();
					mp[make_pair(x, y)] = w;
					stack.push_back(mp);
				} else if ((w & X_ADD) == X_ADD && board[x+1][y] == word[word_index]) {
					stack.back().begin()->second ^= X_ADD;
					if (hasStack(stack, make_pair(size_t(x + 1), y))) {
						continue;
					}
					x++;
					word_index++;
					w = getW(x, y) ^ X_SUB;
					mp.clear();
					mp[make_pair(x, y)] = w;
					stack.push_back(mp);
				} else if ((w & Y_SUB) == Y_SUB && board[x][y-1] == word[word_index]) {
					stack.back().begin()->second ^= Y_SUB;
					if (hasStack(stack, make_pair(x, size_t(y-1)))) {
						continue;
					}
					y--;
					word_index++;
					w = getW(x, y) ^ Y_ADD;
					mp.clear();
					mp[make_pair(x, y)] = w;
					stack.push_back(mp);
				} else if ((w & Y_ADD) == Y_ADD && board[x][y+1] == word[word_index]) {
					stack.back().begin()->second ^= Y_ADD;
					if (hasStack(stack, make_pair(x, size_t(y + 1)))) {
						continue;
					}
					y++;
					word_index++;
					w = getW(x, y) ^ Y_SUB;
					mp.clear();
					mp[make_pair(x, y)] = w;
					stack.push_back(mp);
				} else {
					word_index--;
					stack.pop_back();
				}
			}
			if (word_index == word.size()) {
				return true;
			}
		}
		return false;
	}

	size_t getW(size_t x, size_t y) {
		size_t w = 0;
		if (x > 0) {
			w |= X_SUB;
		}
		if (x < m - 1) {
			w |= X_ADD;
		}
		if (y > 0) {
			w |= Y_SUB;
		}
		if (y < n - 1) {
			w |= Y_ADD;
		}
		return w;
	}

	bool hasStack(vector<map<pair<size_t, size_t>, size_t>> &stack, pair<size_t, size_t> p) {
		if (stack.size() == 0) {
			return false;
		}
		map<pair<size_t, size_t>, size_t>::iterator it;
		for (size_t i = 0; i < stack.size(); i++) {
			it = stack[i].begin();
			if (it->first.first == p.first && it->first.second == p.second) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<vector<char>> board = { {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'} };
	string word = "ABCB";
	cout << s.exist(board, word) << endl;
	return 0;
}