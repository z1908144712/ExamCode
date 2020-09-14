#include <iostream>
#include <vector>
#include <string>
using namespace std;

inline bool isN(long long n, long long m) {
	string s = to_string(n) + to_string(m);
	if (s.size() % 2) {
		return false;
	}
	int begin = 0, end = s.size() - 1;
	while (begin < end) {
		if (s[begin++] != s[end--]) {
			return false;
		}
	}
	return true;
}

int main() {
	long long n;
	cin >> n;
	if (n < 2178) {
		cout << 0 << endl;
	} else if (n <= 10000) {
		cout << 1 << endl;
		cout << 2178 << ' ' << 8712 << endl;
	} else {
		vector<vector<long long>> datas{ {2178, 8712} };
		for (long long i = 10001; i <= n/4; i++) {
			long long m = i * 4;
			if (m > n) {
				continue;
			}
			if (isN(i, m)) {
				datas.push_back({i, m});
			}
		}
		cout << datas.size() << endl;
		for (int i = 0; i < datas.size(); i++) {
			cout << datas[i][0] << " " << datas[i][1] << endl;
		}
	}
	return 0;
}