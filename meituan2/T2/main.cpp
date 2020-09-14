#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> datas(n, vector<int>(n));
	set<int> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> datas[i][j];
		}
	}
	cout << datas[0][0] << " ";
	st.insert(datas[0][0]);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (st.count(datas[i][j])) {
				continue;
			}
			st.insert(datas[i][j]);
			cout << datas[i][j] << " ";
			break;
		}
	}
	return 0;
}

/*
5
1 5 3 4 2
2 3 5 4 1
5 4 1 2 3
1 2 5 4 3
1 4 5 2 3
*/