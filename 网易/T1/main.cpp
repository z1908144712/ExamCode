#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void backtrace(vector<vector<string>> &arr, int i, vector<string>& back) {
	if (i == arr.size()) {
		for (auto j = 0; j < back.size(); j++) {
			cout << back[j];
			if (j != back.size() - 1) {
				cout << "-";
			}
		}
		cout << endl;
		return;
	}
	for (int j = 0; j < arr[i].size(); j++) {
		if (find(back.begin(), back.end(), arr[i][j]) != back.end()) {
			continue;
		}
		back.push_back(arr[i][j]);
		backtrace(arr, i + 1, back);
		back.pop_back();
	}
}

int main() {
	int n;
	cin >> n;
	getchar();
	vector<vector<string>> arr;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		vector<string> a;
		string vs;
		while (getline(ss, vs, ' ')) {
			a.push_back(vs);
		}
		if (a.size()) {
			arr.push_back(a);
		}

	}
	vector<string> back;
	backtrace(arr, 0, back);
	return 0;
}

/*
* 
4
A B C
coder 
C D F G H
TT YY
*/