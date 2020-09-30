#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;
    vector<bool> visited;

    void dfs(string& S, int n, string& s) {
        if (n == S.size()) {
            res.push_back(s);
            return;
        }
        for (int k = 0; k < S.size(); k++) {
            if (visited[k]) {
                continue;
            }
            if (k > 0 && S[k] == S[k - 1] && !visited[k - 1]) {
                continue;
            }
            visited[k] = true;
            s[n] = S[k];
            dfs(S, n + 1, s);
            visited[k] = false;
        }
    }

    vector<string> permutation(string S) {
        sort(S.begin(), S.end());
        string s(S);
        visited = vector<bool>(S.size(), false);
        dfs(S, 0, s);
        return res;
    }
};

int main() {
    for (auto & s : Solution().permutation("OSS")) {
        cout << s << endl;
    }
	return 0;
}