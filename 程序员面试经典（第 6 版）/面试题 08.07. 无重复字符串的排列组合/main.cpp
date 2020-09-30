#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> res;

    void dfs(string& S, int n) {
        if (n == S.size()) {
            res.push_back(S);
        }
        for (int i = n; i < S.size(); i++) {
            swap(S[i], S[n]);
            dfs(S, n + 1);
            swap(S[i], S[n]);
        }
    }

    vector<string> permutation(string S) {
        dfs(S, 0);
        return res;
    }
};

int main() {
    for (auto &s : Solution().permutation("abc")) {
        cout << s << endl;
    }
	return 0;
}