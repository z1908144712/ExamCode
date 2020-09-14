#include <iostream>
#include <vector>
using namespace std;

int maxData(vector<vector<int>>& datas, bool flag) {
	int r = -1;
	if (flag) {
		for (int i = 0; i < datas.size(); i++) {
			if (datas[i][0] == INT_MIN) {
				continue;
			}
			if (r == -1) {
				r = i;
				continue;
			}
			if (datas[r][0] < datas[i][0]) {
				r = i;
			}
		}
	} else {
		for (int i = 0; i < datas.size(); i++) {
			if (datas[i][1] == INT_MIN) {
				continue;
			}
			if (r == -1) {
				r = i;
				continue;
			}
			if (datas[r][1] < datas[i][1]) {
				r = i;
			}
		}
	}
	return r;
}

int f(vector<vector<int>>& datas, int i, int j) {
	if (i == 0 && j == 0) {
		return 0;
	} else if (i == 0) {
		int r = maxData(datas, false);
		int maxi = datas[r][0], maxj = datas[r][1];
		datas[r][0] = datas[r][1] = INT_MIN;
		int c = f(datas, i, j - 1) + maxj;
		datas[r][0] = maxi;
		datas[r][1] = maxj;
		return c;
	} else if (j == 0) {
		int r = maxData(datas, true);
		int maxi = datas[r][0], maxj = datas[r][1];
		datas[r][0] = datas[r][1] = INT_MIN;
		int c = f(datas, i - 1, j) + maxi;
		datas[r][0] = maxi;
		datas[r][1] = maxj;
		return c;
	} else {
		int r = maxData(datas, true);
		int maxi = datas[r][0], maxj = datas[r][1];
		datas[r][0] = datas[r][1] = INT_MIN;
		int ci = f(datas, i - 1, j) + maxi;
		datas[r][0] = maxi;
		datas[r][1] = maxj;
		r = maxData(datas, false);
		maxi = datas[r][0], maxj = datas[r][1];
		datas[r][0] = datas[r][1] = INT_MIN;
		int cj = f(datas, i, j - 1) + maxj;
		datas[r][0] = maxi;
		datas[r][1] = maxj;
		return max(ci, cj);
	}
}

/*
5 3 2
4 2
3 3
5 6
5 3
1 5

*/

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<int>> datas(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		cin >> datas[i][0] >> datas[i][1];
	}
	cout << f(datas, a, b) << endl;
	return 0;
}