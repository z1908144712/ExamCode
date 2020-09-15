#include <iostream>
#include <set>
#include <map>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	set<int> roots;
	map<int, pair<int, int>> nodes;
	for (int i = 0; i < n; i++) {
		int root, child;
		string c;
		cin >> root >> c >> child;
		if (c == "left") {
			nodes[root].first = child;
		} else if (c == "right") {
			nodes[root].second = child;
		}
		if (nodes[root].first > 0 && nodes[root].second > 0) {
			roots.insert(root);
		}
	}
	int cnt = 0;
	for (const auto & root : roots) {
		if (roots.count(nodes[root].first) == 0 && roots.count(nodes[root].second) == 0) {
			cnt++;
		}
	}
	cout << cnt << endl;
	
	return 0;
}

/*
10 9
1 left 2
1 right 3
2 left 4
2 right 5
3 right 6
6 left 7
6 right 8
7 left 9
7 right 10
*/