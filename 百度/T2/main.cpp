#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T;
	cin >> T;
	vector<vector<int>> r;
	while (T) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> np(n);
		vector<pair<int, int>> mp(m);
		for (int i = 0; i < n; i++) {
			cin >> np[i].first;
			np[i].second = i;
		}
		for (int i = 0; i < m; i++) {
			cin >> mp[i].first;
			mp[i].second = i;
		}
		sort(np.begin(), np.end());
		sort(mp.begin(), mp.end());
		vector<int> v(n, -1);
		int j = 0;
		for (int i = 0; i < n && j < m;) {
			if (np[i].first <= mp[j].first) {
				v[i++] = mp[j].second + 1;
			}
			j++;
		}
		r.push_back(v);
		T--;
	}
	for (auto & v : r) {
		for (auto &vi : v) {
			cout << vi << " ";
		}
		cout << endl;
	}
	return 0;
}

/*
2
3 6
33 66 99
3 6 9 34 67 100
3 6
33 66 99
3 6 9 34 67 100
*/