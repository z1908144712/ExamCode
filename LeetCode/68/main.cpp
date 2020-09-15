#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> ans, tmp;
		int count = 0;
		bool flag = false;
		for (int i = 0; i < words.size(); i++) {
			count += words[i].size();
			if (flag || count > (maxWidth - tmp.size())) {
				if (flag) {
					tmp.push_back(words[i]);
				} else {
					count -= words[i].size();
				}
				string st = "";
				if (tmp.size() > 1) {
					if (flag) {
						for (int j = 0; j < tmp.size(); j++) {
							st += tmp[j];
							if (j < tmp.size() - 1) {
								st += " ";
								count++;
							}
						}
						while (count++ < maxWidth) {
							st += " ";
						}
					} else {
						int m = (maxWidth - count) / (tmp.size() - 1);
						int n = (maxWidth - count) % (tmp.size() - 1);
						for (int j = 0; j < tmp.size(); j++) {
							st += tmp[j];
							if (j < tmp.size() - 1) {
								for (int k = 0; k < (n <= 0 ? m : m + 1); k++) {
									st += " ";
								}
								n--;
							}
						}
					}
				} else {
					st += tmp[0];
					for (int j = tmp[0].size(); j < maxWidth; j++) {
						st += " ";
					}
				}
				ans.push_back(st);
				count = 0;
				tmp.clear();
				if (!flag) {
					i--;
				}
			} else if (i == words.size() - 1) {
				flag = true;
				count -= words[i].size();
				i--;
			} else {
				tmp.push_back(words[i]);
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<string> words = { "What","must","be","acknowledgment","shall","be" };
	int maxWidth = 16;
	vector<string> ans = s.fullJustify(words, maxWidth);
	for (string s : ans) {
		cout << s << endl;
	}
	return 0;
}