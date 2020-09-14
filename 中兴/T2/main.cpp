#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int backtrace(vector<pair<int, int>> &arr, unordered_set<int>& st, int m) {
	if (st.size() == arr.size() && m > 0) {
		return INT_MAX;
	}
	if (m <= 0) {
		return st.size();
	}
	int re = INT_MAX;
	for (int i = 0; i < arr.size(); i++) {
		if (st.count(i)) {
			continue;
		}
		st.insert(i);
		int t= m;
		if (arr[i].second >= m) {
			t -= 2*arr[i].first;
		} else {
			t -= arr[i].first;
		}
		int r = backtrace(arr, st, t);
		re = min(r, re);
		st.erase(i);
	}
	return re;
}

int main() {
	int T;
	cin >> T;
	vector<int> res;
	for (int i = 0; i < T; i++) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> arr(n);
		unordered_set<int> st;
		for (int j = 0; j < n; j++) {
			cin >> arr[j].first >> arr[j].second;
		}
		int r = backtrace(arr, st, m);
		res.push_back(r == INT_MAX ? -1 : r);
	}
	for (auto & i : res) {
		cout << i << endl;
	}
	return 0;
}

/*

3
3 100
10 20
45 89
5 40
3 100
10 20
45 90
5 40
3 100
10 20
45 84
5 40

 */