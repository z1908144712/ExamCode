#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

#define  __int128 unsigned long long

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int left = n - 1, right = n - 1;
	__int128 cnt = 0, maxx = 0;
	int minn = 0;
	while (left >= 0) {
		int t = 0;
		maxx = arr[left];
		while (left > 0 && arr[left] >= arr[left - 1]) {
			left--;
			maxx = max(maxx, (__int128)arr[left]);
			if (maxx == arr[left]) {
				t++;
			}
		}
		minn += right - left - t;
		cnt += (__int128)((__int128)arr[right] * (__int128)(right - left + 1));
		right = --left;
	}
	cout << cnt << " " << minn << endl;
	return 0;
}

/*
6
3 3 3 5 5 5
 */