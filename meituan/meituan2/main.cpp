#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<string>> datas(n, vector<string>(2));
	for (int i = 0; i < n; i++) {
		cin >> datas[i][0] >> datas[i][1];
	}
	int count = 0;
	string begin = datas[0][0], end = datas[0][1];
	for (int i = 1; i < datas.size(); i++) {
		if (datas[i][0] == end) {
			end = datas[i][1];
			if (begin == end) {
				count++;
			}
		} else {
			begin = datas[i][0];
			end = datas[i][1];
		}
	}
	cout << count << endl;
	return 0;
}