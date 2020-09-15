#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		cout << s1 << " " << s2 << endl;
		if (s1.size() == s2.size()) {
			if (s1 == s2) {
				return true;
			} else {
				int len = s1.size();
				if (len == 0) {
					return true;
				} else if (len == 1) {
					return s1 == s2;
				} else if (len == 2) {
					return (s1 == s2 || (s1[0] == s2[1] && s1[1] == s2[0]));
				} else {
					map<char, int> m;
					for (size_t i = 0; i < len; i++) {
						if (m.count(s1[i])) {
							m[s1[i]] += 1;
						} else {
							m[s1[i]] = 1;
						}
						if (m.count(s2[i])) {
							m[s2[i]] -= 1;
						} else {
							m[s2[i]] = -1;
						}
					}
					for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
						if (it->second != 0) {
							return false;
						}
					}
					for (size_t i = 1; i < len; i++) {
						if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
							return true;
						}
						if (isScramble(s1.substr(0, i), s2.substr(len - i)) && isScramble(s1.substr(i), s2.substr(0, len - i))) {
							return true;
						}
					}
					return false;
				}
			}
		} else {
			return false;
		}
	}
};

int main() {
	Solution s;
	cout << s.isScramble("abcdefghijklmnopq", "efghijklmnopqcadb") << endl;
	return 0;
}