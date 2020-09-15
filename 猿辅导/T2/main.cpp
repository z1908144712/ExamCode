#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int mod = 1e7;

int cal(vector<string> &arr, int i, int j) {
	if (i >= j) {
		return atoi(arr[i].c_str());
	}
	if (arr[i] == "(" && arr[j] == ")") {
		i++;
		j--;
		if (arr[i] == "+") {
			return ((cal(arr, i + 1, j - 1) + cal(arr, i + 2, j - 1)) % mod + mod) % mod;
		} else if (arr[i] == "-") {
			return ((cal(arr, i + 1, j - 1) - cal(arr, i + 2, j - 1)) % mod + mod) % mod;
		} else if (arr[i] == "*") {
			return ((cal(arr, i + 1, j - 1) * cal(arr, i + 2, j - 1)) % mod + mod) % mod;
		} else {
			return INT_MIN;
		}
	} else {
		return INT_MIN;
	}
}

int main() {
	int n;
	cin >> n;
	getchar();
	vector<string> res;
	for (int i = 0; i < n; i++) {
		string s;
		int idx = 0;
		getline(cin, s);
		while ((idx = s.find('(', idx)) != string::npos) {
			idx++;
			s.insert(s.begin() + idx, ' ');
		}
		idx = 0;
		while ((idx = s.find(')', idx)) != string::npos) {
			s.insert(s.begin() + idx, ' ');
			idx+=2;
		}
		stringstream ss(s);
		string v;
		vector<string> arr;
		while (getline(ss, v ,' ')) {
			arr.push_back(v);
		}
		int r = cal(arr, 0, arr.size() - 1);
		if (r == INT_MIN) {
			res.push_back("invalid");
		} else {
			res.push_back(to_string(r));
		}
	}
	for (auto &r : res) {
		cout << r << endl;
	}
	return 0;
}

/*
4
(- 0 1)
(+ 2 20)
+ 1 2)
(2 2)
*/