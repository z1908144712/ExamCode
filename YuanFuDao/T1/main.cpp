#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n;
	map<int, int> datas;
	for (int i = 1; i <= n; i++) {
		cin >> datas[i];
	}
	int cur = 1;
	while (cur <= n) {
		cout << datas[cur] << " ";
		cur *= 2;
	}
	int tmp = cur /= 2;
	cur = tmp + 1;
	while (cur <= n) {
		cout << datas[cur++] << " ";
	}
	cur = tmp - 1;
	if (cur == 1) {
		return 0;
	}
	while ((cur - 1)*2 > n) {
		cur--;
	}
	while (cur < tmp) {
		cout << datas[cur++] << " ";
	}
	cur = (tmp - 1) / 2;
	while (cur > 1) {
		cout << datas[cur] << " ";
		cur /= 2;
	}
	return 0;
}