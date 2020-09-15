#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		B[i] = A[i];
	}
	sort(A.begin(), A.end());
	int t = n / 2 - 1;
	for (int i = 0; i < n; i++) {
		if (B[i] > A[t]) {
			cout << A[t] << endl;
		} else {
			cout << A[t + 1] << endl;
		}
	}
	return 0;
}

/*

6
1 2 3 4 5 6
*/