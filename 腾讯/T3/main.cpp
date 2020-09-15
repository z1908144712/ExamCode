#include <iostream>
#include <map>
#include <vector> 
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	map<string, int> mp;
	vector<set<string>> vt(n + 1,set<string>());
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (mp.count(s)) {
			vt[mp[s]].erase(s);
			mp[s]++;
			vt[mp[s]].insert(s);
		} else {
			vt[1].insert(s);
			mp[s] = 1;
		}
	}
	int cnt = 0;
	for (int i = n; i >= 1 && cnt < k; i--) {
		if (!vt.empty()) {
			for (set<string>::iterator it = vt[i].begin(); cnt < k && it != vt[i].end(); it++) {
				cout << *it << " " << i << endl;
				cnt++;
			}
		}
	}
	cnt = 0;
	for (int i = 1; i <= n && cnt < k; i++) {
		if (!vt[i].empty()) {
			for (set<string>::iterator it = vt[i].begin(); cnt < k && it != vt[i].end(); it++) {
				cout << *it << " " << i << endl;
				cnt++;
			}
		}
	}
	return 0;
}

/*
4 2
1
2
3
4

4 2
1
1
2
3
*/