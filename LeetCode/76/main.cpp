#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0 || t.size() == 0) {
			return "";
		}
		map<char, int> dictT;
		for (int i = 0; i < t.size(); i++) {
			if (dictT.count(t[i])) {
				dictT[t[i]]++;
			} else {
				dictT[t[i]] = 1;
			}
		}
		int required = dictT.size();
		vector<pair<int, char>> filteredS;
		for (int i = 0; i < s.size(); i++) {
			if (dictT.count(s[i])) {
				filteredS.push_back(make_pair(i, s[i]));
			}
		}
		int left = 0, right = 0, formed = 0;
		int ans[] = {-1, 0, 0};
		map<char, int> windowCounts;
		while (right < filteredS.size()) {
			char c = filteredS[right].second;
			if (windowCounts.count(c)) {
				windowCounts[c]++;
			} else {
				windowCounts[c] = 1;
			}
			if (dictT.count(c) && windowCounts[c] == dictT[c]) {
				formed++;
			}
			while (left <= right && formed == required) {
				c = filteredS[left].second;
				int end = filteredS[right].first;
				int start = filteredS[left].first;
				if (ans[0] == -1 || (end - start + 1) < ans[0]) {
					ans[0] = end - start + 1;
					ans[1] = start;
					ans[2] = end;
				}
				windowCounts[c]--;
				if (dictT.count(c) && windowCounts[c] < dictT[c]) {
					formed--;
				}
				left++;
			}
			right++;
		}
		return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
	}
};

int main() {
	Solution s;
	cout << s.minWindow("ADOBECODEBANC", "ABC") << endl;
	return 0;
}