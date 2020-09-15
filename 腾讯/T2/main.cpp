#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		vector<int> vk(k);
		for (int j = 0; j < k; j++) {
			cin >> vk[j];
		}
		sort(vk.begin(), vk.end());
		arr.push_back(vk);
	}
	sort(arr.begin(), arr.end());
	vector<bool> visited(m, false);
	int cnt = 0;
	unordered_set<int> st;
	st.insert(0);
	while (cnt < arr.size()) {
		bool c = false;
		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) {
				for (int j = 0; j < arr[i].size(); j++) {
					if (st.count(arr[i][j])) {
						c = true;
						st.insert(arr[i].begin(), arr[i].end());
						visited[i] = true;
						cnt++;
						break;
					}
				}
			}
		}
		if (!c) {
			break;
		}
	}
	cout << st.size() << endl;
	return 0;
}

/*
50 5
2 1 2
5 10 11 12 13 14
2 0 1
2 49 2
4 6 7 8 2

*/