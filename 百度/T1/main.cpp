#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> r;
	int T;
	cin >> T;
	while (T) {
		int L, n;
		cin >> L >> n;
		vector<int> v(L + 1, 0);
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			for (int j = l; j <= r; j++) {
				v[j]++;
			}
		}
		r.push_back(v);
		T--;
	}
	for (auto & v : r) {
		for (int i = 1; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

/*

2
6 3
1 2
4 5
3 6
6 3
1 2
4 5
3 6
*/