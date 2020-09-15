#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		if (s[0] == '0') {
			return 0;
		}
		int pre = 1, cur = 1;
		for (size_t i = 1; i < s.size(); i++) {
			int tmp = cur;
			if (s[i] == '0') {
				if (s[i-1] == '1' || s[i-1] == '2') {
					cur = pre;
				} else {
					return 0;
				}
			} else if (s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6')){
				cur += pre;
			}
			pre = tmp;
		}
		return cur;
	}
};

int main() {
	Solution s;
	cout << s.numDecodings("9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253") << endl;
	return 0;
}