#include <iostream>
#include <vector>
#include <set>

using namespace std;

int dfs(vector<vector<int>> &datas, set<int>& st, int a) {
	int r = -1;
	for (int i = 1; i < datas.size(); i++) {
		if (datas[a][i]) {
			if (st.count(i)) {
				continue;
			}
			st.insert(i);
			r = dfs(datas, st, i);
			if (r != -1) {
				return r;
			}
			st.erase(i);
		}
	}
	for (int i = 1; i < datas.size(); i++) {
		if (datas[i][a]) {
			if (st.count(i)) {
				continue;
			}
			st.insert(i);
			r = dfs(datas, st, i);
			if (r != -1) {
				return r;
			}
			st.erase(i);
		}
	}
	return a;
}

int dfs(vector<vector<int>>& datas, set<int>& st, int a, int& b) {
	if (a == b) {
		return a;
	}
	int r = -1;
	for (int i = 1; i < datas.size(); i++) {
		if (datas[a][i]) {
			if (st.count(i)) {
				continue;
			}
			st.insert(i);
			r = dfs(datas, st, i, b);
			if (r != -1) {
				return r;
			}
			st.erase(i);
		}
	}
	for (int i = 1; i < datas.size(); i++) {
		if (datas[i][a]) {
			if (st.count(i)) {
				continue;
			}
			st.insert(i);
			r = dfs(datas, st, i, b);
			if (r != -1) {
				return r;
			}
			st.erase(i);
		}
	}
	return r;
}

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<vector<int>> datas(n + 1, vector<int>(n + 1, 0));
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		datas[a][b] = 1;
	}
	set<int> st;
	st.insert(y);
	st.insert(x);
	int r = dfs(datas, st, y);
	st.clear();
	st.insert(x);
	dfs(datas, st, x, r);
	cout << st.size() - 1  << endl;
	return 0;
}

/*
5 1 2
2 1
3 1
4 2
5 3
*/