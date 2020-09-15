#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int cnt = 0;
int cn = 0;


struct my_hash {
    size_t operator() (const pair<int, int> &a) const {
        return hash<int>()(a.first) ^ hash<int>()(a.second);
    }
};

unordered_map<pair<int, int>, int, my_hash> mp;

void dfs(int n, int& k, int& d, int maxx) {
    if (0 == n) {
        if (maxx >= d) {
            cnt++;
        }
        return;
    }
    if (mp.count({n, maxx})) {
        cnt += mp[{n, maxx}];
        return;
    }
    int t = cnt;
    for (int i = 1; i <= k; i++) {
        if (n - i < 0){
            return;
        }
        dfs(n - i , k, d, max(i, maxx));
    }
    mp[{n, maxx}] = cnt - t;
}

void dfst(int n, int& k, int& d, int maxx) {
    if (0 == n) {
        if (maxx >= d) {
            cn++;
        }
        return;
    }
    for (int i = 1; i <= k; i++) {
        if (n - i < 0) {
            return;
        }
        dfst(n - i, k, d, max(i, maxx));
    }
}

int main() {
	int n, k, d;
	cin >> n >> k >> d;
	dfs(n, k,d, 0);
    cout << cnt << endl;
    dfst(n, k, d, 0);
    cout << cn << endl;
	return 0;
}

/*
5 3 2
 */