#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string s;
	vector<string> r;
	string cs = "~`!@#$%^&*()_+-=[]{}\\|:;\"'<>?/";
	while (cin >> s) {
		if (s.size() < 8) {
			r.push_back("Irregular password");
			break;
		}
		bool isnum = false, isUpper = false, isLower = false, isSp = false;
		for (auto &c : s) {
			if (c >= '0' && c <= '9') {
				if (!isnum) {
					isnum = true;
				}
			} else if (c >= 'A' && c <= 'Z') {
				if (!isUpper) {
					isUpper = true;
				}
			} else if (c >= 'a' && c <= 'z') {
				if (!isLower) {
					isLower = true;
				}
			} else if (find(s.begin(), s.end(), c) != s.end()) {
				if (!isSp) {
					isSp = true;
				}
			}
		}
		r.push_back(((isnum && isUpper && isLower && isSp) ? "Ok" : "Irregular password"));
	}
	for (auto &i : r) {
		cout << i << endl;
	}
	return 0;
}