#include <iostream>
#include <vector>
using namespace std;
static int cnt = 0;

void subset(vector<int> &datas, vector<bool> &visit, int cur, int& n, int& k) {
	if (cur == n) {
		vector<int> data;
		for (int i = 0; i < n; i++) {
			if (visit[i]) {
				for (int j = 0; j < data.size(); j++) {
					if ((datas[i] + data[j]) % k == 0) {
						return;
					}
				}
				data.push_back(datas[i]);
			}
		}
		cnt++;
		if (cnt > 1000000007) {
			cnt %= 1000000007;
		}
	} else {
		visit[cur] = true;
		subset(datas, visit, cur + 1, n, k);
		visit[cur] = false;
		subset(datas, visit, cur + 1, n, k);
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	cnt = 0;
	vector<int> datas(n);
	for (int i = 0; i < n; i++) {
		cin >> datas[i];
	}
	vector<bool> visit(n);
	subset(datas, visit, 0, n, k);
	cout << cnt << endl;
	return 0;
}