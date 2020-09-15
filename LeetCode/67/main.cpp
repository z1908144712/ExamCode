#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		int maxLen = a.size() > b.size() ? a.size() : b.size();
		int minLen = a.size() < b.size() ? a.size() : b.size();
		string ans;
		int flag = 0, tmp, j;
		if (maxLen == a.size()) {
			ans = a;
		} else {
			ans = b;
		}
		j = maxLen - 1;
		for (int i = minLen - 1; i >= 0; i--, j--) {
			if (maxLen == a.size()) {
				tmp = b[i] - '0' + ans[j] - '0' + flag;
			} else {
				tmp = a[i] - '0' + ans[j] - '0' + flag;
			}
			flag = tmp / 2;
			ans[j] = tmp % 2 + '0';
		}
		while (j >= 0) {
			if (flag) {
				tmp = ans[j] - '0' + flag;
				flag = tmp / 2;
				ans[j] = tmp % 2 + '0';
				j--;
			} else {
				break;
			}
		}
		if (flag) {
			ans.insert(ans.begin(), '1');
		}
		return ans;
	}
};

int main() {
	Solution s;
	cout << s.addBinary("1010", "1011") << endl;
	return 0;
}