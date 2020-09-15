#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		int an, bn, cn, dn;
		for (int a = 1; a < 4; a++) {
			for (int b = 1; b < 4; b++) {
				for (int c = 1; c < 4; c++) {
					for (int d = 1; d < 4; d++) {
						if (a+b+c+d == s.size()) {
							an = stoi(s.substr(0, a));
							bn = stoi(s.substr(a, b));
							cn = stoi(s.substr(a + b, c));
							dn = stoi(s.substr(a + b + c));
							if (an <= 255 && bn <= 255 && cn <= 255 && dn <= 255) {
								string ip = to_string(an) + "." + to_string(bn) + "." + to_string(cn) + "." + to_string(dn);
								if (ip.size()-3 == s.size()) {
									ans.push_back(ip);
								}
							}
						}
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<string> ans = s.restoreIpAddresses("010010");
	for (size_t i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}