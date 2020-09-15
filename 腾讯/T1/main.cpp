#include <iostream>
#include <vector>

using namespace std;

int main() {
	int m, n;
	cin >> m;
	vector<int> mp(m);
	for (int i = 0; i < m; i++) {
		cin >> mp[i];
	}
	cin >> n;
	vector<int> np(n);
	for (int i = 0; i < n; i++) {
		cin >> np[i];
	}
	int i = 0, j = 0;
	while (i < m && j < n) {
		if (mp[i] == np[j]) {
			cout << mp[i] << " ";
			i++;
			j++;
		} else if (mp[i] < np[j]) {
			j++;
		} else if (mp[i] > np[j]) {
			i++;
		}
	}
	return 0;
}

/*
6
6 5 4 3 2 1
5
6 5 3 2 1
*/