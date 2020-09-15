#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> arr(2*n);
	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
		if (s[i] == 'R') {
			arr[i] = -arr[i];
		}
	}
	int b = n, r = -n;
	int cnt = 0;
	while (b > 0 && r < 0) {
		auto bi = find(arr.begin(), arr.end(), b);
		auto ri = find(arr.begin(), arr.end(), r);
		if (bi < ri) {
			cnt += arr.size() - (ri - arr.begin() + 1);
			arr.erase(ri);
			r++;
		} else {
			cnt += arr.size() - (bi - arr.begin() + 1);
			arr.erase(bi);
			b--;
		}
	}
	if (b == 0) {
		r = -r;
		for (int i = 0; i < arr.size(); i++) {
			arr[i] = -arr[i];
		}
	} else {
		r = b;
	}
	while (r > 0) {
		auto ri = find(arr.begin(), arr.end(), r);
		cnt += arr.size() - (ri - arr.begin() + 1);
		arr.erase(ri);
		r--;
	}
	cout << cnt << endl;
	return 0;
}

/*
3
BRRBRB
2 3 1 1 2 3

*/