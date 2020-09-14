#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> ret;
        for (int i = 0; i < (int)words.size(); i++) {
            for (int j = 0; j < (int)words.size(); j++) {
                if (i != j) {
                    string& iword = words[i];
                    string& jword = words[j];
                    if ((iword.size() == 0 || jword.size() == 0 || iword[0] == jword[jword.size() - 1]) && isRound(iword, jword)) {
                        ret.push_back({i, j});
                    }
                }
            }
        }
        return ret;
    }

    bool isRound(string &a, string &b) {
        int ai = 0, bi = b.size() - 1;
        while (ai < a.size() && bi >= 0) {
            if (a[ai++] != b[bi--]) {
                return false;
            }
        }
        if (ai < a.size()) {
            int aj = a.size() - 1;
            while (ai < aj) {
                if (a[ai++] != a[aj--]) {
                    return false;
                }
            }
        }
        if (bi > 0) {
            int bj = 0;
            while (bj < bi) {
                if (b[bj++] != b[bi--]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    //vector<string> words = { "abcd","dcba","lls","s","sssll" };
    vector<string> words = { "a","" };
    vector<vector<int>> ret = Solution().palindromePairs(words);
    for (auto& r : ret) {
        cout << r[0] << "," << r[1] << endl;
    }
    return 0;
}