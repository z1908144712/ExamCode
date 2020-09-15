#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (i + 1 < s.size() && s[i + 1] != ' ') {
					count = 0;
				}
			}
			else {
				count++;
			}
		}
		return count;
	}
};

int main() {
	Solution s;
	cout << s.lengthOfLastWord("a ") << endl;
	return 0;
}