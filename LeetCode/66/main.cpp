#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int flag;
		for (int i = digits.size() - 1; i >= 0; i--) {
			if (i == digits.size() - 1) {
				digits[i] += 1;
				flag = digits[i] / 10;
				if (flag) {
					digits[i] %= 10;
				} else {
					break;
				}
				continue;
			}
			if (flag) {
				digits[i] += flag;
				flag = digits[i] / 10;
				digits[i] %= 10;
			} else {
				break;
			}
		}
		if (flag) digits.insert(digits.begin(), flag);
		return digits;
	}
};

int main() {
	Solution s;
	vector<int> digits = {9};
	s.plusOne(digits);
	for (vector<int>::iterator it = digits.begin(); it < digits.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}