#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s = to_string(n);
	reverse(s.begin(), s.end());
	n = atoi(s.c_str());
	int r = 0, e = 1;
	while (n) {
		r += n % 5 * e;
		n /= 5;
		e *= 10;
	}
	cout << r << endl;
	return 0;
}