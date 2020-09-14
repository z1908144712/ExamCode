#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int cnt = 0;
map<int, int> mp;

void sub(vector<int>& datas, int m) {
	if (m < 0) {
		return;
	}
	if (m == 0) {
		cnt++;
		if (cnt >= 1000000007) {
			cnt %= 1000000007;
		}
	}
	if (mp.count(m)) {
		cnt += mp[m];
		if (cnt >= 1000000007) {
			cnt %= 1000000007;
		}
		return;
	}
	int t = cnt;
	for (auto &i : datas) {
		if (m - i < 0) {
			break;
		}
		sub(datas, m - i);
	}
	mp[m] = (1000000007 + cnt - t) % 1000000007;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> datas(n);
	for (int i = 0; i < n; i++) {
		cin >> datas[i];
	}
	sort(datas.begin(), datas.end());
	sub(datas, m);
	cout << cnt << endl;
	return 0;
}

/*
3 3
1
2
2
*/