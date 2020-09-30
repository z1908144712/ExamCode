#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<bool> res;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int n = str.size();
		if (n % 3 != 0) {
			res.push_back(false);
			continue;
		}
		unordered_set<string> st;
		for (int j = 0; j < str.size(); j += 3) {
			string t = str.substr(j, 3);
		    if (st.count(t) == 0) {
				bool flag = false;
		        for (auto &val : st) {
					int cnt = 0;
					for (int k = 0; k < 3; k++) {
					    if (val[k] != t[k]) {
							cnt++;
					    }
					}
					if (cnt > 1) {
						flag = true;
						res.push_back(false);
					    break;
					}
		        }
				if (flag) {
					break;
				}
				st.insert(t);
		    }
		}
		res.push_back(true);
	}
	for (auto r : res) {
		cout << (r ? "Yes":"No") << endl;
	}
	return 0;
}