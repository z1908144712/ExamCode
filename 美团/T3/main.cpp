#include <iostream>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int r = 0;
		for (int i = 1; i <= n; i++) {
			cout << i << " -> ";
			r = 0;
			for (int j = 1; j <= n; j++) {
				cout << (i % j) << " ";
				r = r ^ (i % j);
			}
			cout << " -> " << r << endl;
		}
		cout << r << endl;
	}
	return 0;
}