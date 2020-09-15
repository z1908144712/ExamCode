#include <iostream>

using namespace std;

class Solution {
public:
	bool isNumber(string s) {
		if (s.size() == 0) {
			return false;
		} else {
			bool flag = false, integer_number = false, float_number = false, point = false, science_number = false, science_flag = false;
			for (int i = 0; i < s.size(); i++) {
				if ((s[i] >= '0'&& s[i] <= '9')) {
					if (!point) {
						integer_number = true;
						if (science_flag) science_number = true;
					} else {
						integer_number = false;
						float_number = true;
						if (science_flag) return false;
					}
				} else if (s[i] == ' ') {
					if (i+1 < s.size() && s[i] == s[i + 1]) continue;
					if (i != s.size()-1 && (integer_number || point || science_flag || flag)) return false;
				} else if (s[i] == '+' && !flag && !(integer_number || point)) {
					flag = true;
				} else if (s[i] == '-' && !flag && !(integer_number || point)) {
					flag = true;
				} else if (s[i] == '.' && !point && !science_flag) {
					point = true;
				} else if (s[i] == 'e' && !science_flag && (integer_number || float_number)) {
					point = false;
					integer_number = false;
					float_number = false;
					flag = false;
					science_flag = true;
				} else {
					return false;
				}
			}
			return (science_flag && science_number) || float_number || integer_number;
		}
	}
};

int main() {
	Solution s;
	cout << s.isNumber(" 005047e+6") << endl;
}