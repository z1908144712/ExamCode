#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int left = 0, right = s.size()-1;
		while (left < right) {
			if ((s[left] >= '0' && s[left] <= '9') ) {
				if (s[right] >= '0' && s[right] <= '9') {
					if (s[left] == s[right]) {
						left++;
						right--;
					} else {
						return false;
					}
				} else if ((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z')) {
					return false;
				} else {
					right--;
				}
			} else if ((s[left] >= 'a' && s[left] <= 'z') || (s[left] >= 'A' && s[left] <= 'Z')) {
				if ((s[right] >= 'a' && s[right] <= 'z') || (s[right] >= 'A' && s[right] <= 'Z')) {
					if (s[left] == s[right] || abs(s[left]- s[right]) == 'a'-'A') {
						left++;
						right--;
					} else {
						return false;
					}
				} else if (s[right] >= '0' && s[right] <= '9') {
					return false;
				} else {
					right--;
				}
			} else {
				left++;
			}
		}
		return true;
	}
};

int main() {
	Solution s;
	cout << s.isPalindrome("0P") << endl;
	return 0;
}