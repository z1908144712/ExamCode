#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find(vector<int> &pre, int n) {
	return pre[n] == n ? n : pre[n] = find(pre, pre[n]);
}

void merge(vector<int>& pre, int a, int b) {
	if (a == b) {
		return;
	}
	int fa = find(pre, a), fb = find(pre, b);
	if (fa != fb) {
		pre[fa] = fb;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	int m, n;
	cin >> n >> m;
	//init
	vector<int> pre(n + 1);
	for (int i = 1; i <= n; i++) {
		pre[i] = i;
	}
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		merge(pre, a, b);
	}
	map<int, vector<int>> mp;
	for (int i = 1; i <= n; i++) {
		if (pre[i] == i && !mp.count(i)) {
			mp[i] = {i};
		} else {
			int p = find(pre, i);
			if (mp.count(p)) {
				mp[p].push_back(i);
			} else {
				mp[p] = {i};
			}
		}
	}
	cout << mp.size() << endl;
	for (auto &m : mp) {
		for (auto &i : m.second) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
6 5
1 2
2 3
3 1
5 4
6 6

*/