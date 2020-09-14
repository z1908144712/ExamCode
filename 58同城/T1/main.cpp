#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(vector<vector<char>> &arr, int i, int j) {
	if (i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size()) {
		return;
	}
	if (arr[i][j] == '1') {
		arr[i][j] = '0';
		dfs(arr, i + 1, j);
		dfs(arr, i - 1, j);
		dfs(arr, i, j + 1);
		dfs(arr, i , j - 1);
	}
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<char>> arr(m, vector<char>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '1') {
				cnt++;
				dfs(arr, i, j);
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

/*
3
3
1 1 0
1 0 1
0 0 0

2

3
5
1 1 0 0 0
1 0 1 1 0
0 1 0 0 1

4

 */