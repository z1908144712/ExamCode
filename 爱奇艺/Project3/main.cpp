#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> res;

void backtrace(vector<int>&arr, int idx, vector<int>& back) {
    if (back.size() == 3) {
		if (back[0] + back[1] + back[2] == 0) {
			if (find(res.begin(), res.end(), back) == res.end()) {
				res.push_back(back);
			}
		}
		return;
    }
	for (int i = idx; i < arr.size(); i++) {
		back.push_back(arr[i]);
		backtrace(arr, i + 1, back);
		back.pop_back();
	}
}

int main() {
	vector<int> arr;
	int x;
	while (cin >> x) {
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());
	vector<int> back;
	backtrace(arr, 0, back);
	for (auto &x : res) {
	    for (auto &a : x) {
			cout << a << " ";
	    }
		cout << endl;
	}
	return 0;
}

/*
-1 0 1 2 -1 -4
 */