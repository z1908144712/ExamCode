#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int L = 0, R = n - 1;
	bool LM = false, LT = false, RT = false, RM = false;
	while (L < R && !LT) {
		if (s[L] == 'M') {
			LM = true;
		}
		if (s[L] == 'T') {
			LT = LM;
		}
		L++;
	}
	while (L < R && !RM) {
		if (s[R] == 'T') {
			RT = true;
		}
		if (s[R] == 'M') {
			RM = RT;
		}
		R--;
	}
	cout << s.substr(L, R - L + 1) <<endl;
	return 0;
}

/*
10
MMATSATMMT
*/