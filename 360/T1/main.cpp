#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr(n);
	vector<int> up, down;
	//vector<vector<int>> arrm(m, vector<int>(2));
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (b == 1) {
			up.push_back(a);
		} else {
			down.push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {

	}
	return 0;
}