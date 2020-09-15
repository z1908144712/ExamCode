#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

bool isvaild(vector<vector<bool>>& house) {
	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < house[i].size(); j++) {
			if (!house[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void backtrace(vector<vector<bool>>& house, int x1, int y1, int& x, int &y, int& x2, int& y2) {
	if (x1 < 0 || x1 >= x || y1 < 0 || y1 >= y) {
		return;
	}
	if (house[x1][y1]) {
		return;
	}
	house[x1][y1] = true;
	if (x1 == x2 && y1 == y2 && isvaild(house)) {
		cnt++;
		house[x1][y1] = false;
		return;
	}
	backtrace(house, x1 - 1, y1, x, y, x2, y2);
	backtrace(house, x1 + 1, y1, x, y, x2, y2);
	backtrace(house, x1, y1 - 1, x, y, x2, y2);
	backtrace(house, x1, y1 + 1, x, y, x2, y2);
	house[x1][y1] = false;
}

int main() {
	int x, y, x1, y1, x2, y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	vector<vector<bool>> house(x, vector<bool>(y, false));
	backtrace(house, x1, y1, x, y, x2, y2);
	cout << cnt << endl;
	return 0;
}

/*
4 4
3 0
3 3

4 4
3 0
0 3
*/