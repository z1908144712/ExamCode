#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> &data) {
	int max = INT_MIN, sum = 0;
	for (int i = 0; i < data.size(); i++) {
		sum += data[i];
		if (max < sum) {
			max = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	return max;
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> datas(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> datas[j][i];
		}
	}
	int max = INT_MIN;
	vector<int> tmp(m);
	for (int i = 0; i < n; i++) {
		fill(tmp.begin(), tmp.end(), 0);
		for (int k = i; k < n; k++) {
			for (int j = 0; j < m; j++) {
				tmp[j] += datas[k][j];
			}
			int mx = findMax(tmp);
			if (max < mx) {
				max = mx;
			}
		}
	}
	if (n <= 2) {
		cout << max << endl;
		return 0;
	}
	for (int i = n - 1; i > 1; i--) {
		swap(datas[i], datas[i - 1]);
	}
	for (int i = 0; i < n; i++) {
		fill(tmp.begin(), tmp.end(), 0);
		for (int k = i; k < n; k++) {
			for (int j = 0; j < m; j++) {
				tmp[j] += datas[k][j];
			}
			int mx = findMax(tmp);
			if (max < mx) {
				max = mx;
			}
		}
	}
	cout << max << endl;
	return 0;
}

/*
4 4
0 -2 -7 0
9 2 -6 2
-4 1 -4 1
-1 8 0 -2
*/