#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<string> paths;

unordered_set<string> st{"abd", "abd","ebc","edc","edf"};

bool found = false;

void dfs(unordered_set<char>& changes, string& start, string& end, int idx) {
	if (idx == end.size()) {
		if (start == end) {
			found = true;
		}
		return;
	}
	for (auto&c : changes) {
		if (c == start[idx]) {
			continue;
		}
		char t = start[idx];
		start[idx] = c;
		if (st.count(start)) {
			paths.push_back(start);
			dfs(changes, start, end, idx + 1);
			if (found) {
				return;
			}
			paths.pop_back();
		}
		start[idx] = t;
	}
}

int main() {
	string start = "abc", end = "edf";
	unordered_set<char> changes;
	for (auto& s : st) {
		for (auto& c : s) {
			if (!changes.count(c)) {
				changes.insert(c);
			}
		}
	}
	dfs(changes, start, end, 0);
	for (auto &s : paths) {
		cout << s << endl;
	}
	return 0;
}