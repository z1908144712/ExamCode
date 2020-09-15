#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> ans;
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
			return ans;
		}
		map<string, vector<string>> map;
		bfs(beginWord, endWord, wordList, map);
		vector<string> temp;
		temp.push_back(beginWord);
		findLaddersHelper(beginWord, endWord, map, temp, ans);
		return ans;
	}

	void findLaddersHelper(string beginWord, string endWord, map<string, vector<string>> map, vector<string>& temp, vector<vector<string>>& ans) {
		if (beginWord == endWord) {
			ans.push_back(temp);
			return;
		}
		vector<string> neighbors = map.count(beginWord) ? map.find(beginWord)->second : vector<string>();
		for (string neighbor : neighbors) {
			temp.push_back(neighbor);
			findLaddersHelper(neighbor, endWord, map, temp, ans);
			temp.pop_back();
		}
	}

	void bfs(string beginWord, string endWord, vector<string>& wordList, map<string, vector<string>>& map) {
		set<string> set1, set2;
		set1.insert(set1.begin(), beginWord);
		set2.insert(set2.begin(), endWord);
		set<string> wordSet(wordList.begin(), wordList.end());
		bfsHelper(set1, set2, wordSet, true, map);
	}

	bool bfsHelper(set<string> set1, set<string> set2, set<string> wordSet, bool direction, map<string, vector<string>>& map) {
		if (set1.size() == 0) {
			return false;
		}
		if (set1.size() > set2.size()) {
			return bfsHelper(set2, set1, wordSet, !direction, map);
		}
		removeAll(wordSet, set1);
		removeAll(wordSet, set2);
		bool done = false;
		set<string> set;
		for (string str : set1) {
			for (size_t i = 0; i < str.size(); i++) {
				string s = str;
				for (char ch = 'a'; ch <= 'z'; ch++) {
					if (s[i] == ch) {
						continue;
					}
					s[i] = ch;
					string key = direction ? str : s;
					string val = direction ? s : str;
					vector<string> list = map.count(key) ? map.find(key)->second : vector<string>();
					if (set2.count(s)) {
						done = true;
						list.insert(list.begin(), val);
						map[key] = list;
					}
					if (!done && wordSet.count(s)) {
						set.insert(set.begin(), s);
						list.insert(list.begin(), val);
						map[key] = list;
					}
				}
			}
		}
		return done || bfsHelper(set2, set, wordSet, !direction, map);
	}

	void removeAll(set<string>& wordSet, set<string> set) {
		for (string str : set) {
			if (wordSet.count(str)) {
				wordSet.erase(str);
			}
		}
	}
};

int main() {
	Solution s;
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	vector<vector<string>> ans = s.findLadders(beginWord, endWord, wordList);
	for (size_t i = 0; i < ans.size(); i++) {
		cout << "{ ";
		for (size_t j = 0; j < ans[i].size(); j++) {
			cout << ans[i][j] << " ";
		}
		cout << "}\n";
	}
	return 0;
}