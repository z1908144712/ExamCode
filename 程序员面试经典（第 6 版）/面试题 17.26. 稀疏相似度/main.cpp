#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        vector<string> res;
        vector<vector<int>> help(docs.size(), vector<int>(docs.size(), 0));
        map<int, vector<int>> mp;
        for (int i = 0; i < docs.size(); i++) {
            for (int j = 0; j < docs[i].size(); j++) {
                for (auto& k : mp[docs[i][j]]) {
                    help[i][k]++;
                }
                mp[docs[i][j]].push_back(i);
            }
            for (int k = 0; k < docs.size(); k++) {
                if (help[i][k] > 0) {
                    ostringstream oss;
                    oss.precision(4);
                    oss << k << "," << i << ": " << fixed <<(help[i][k] * 1.0 / (docs[i].size() + docs[k].size() - help[i][k]) + 1e-9);
                    res.push_back(oss.str());
                }
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> docs{
        {14, 15, 100, 9, 3} ,
        {32, 1, 9, 3, 5},
        {15, 29, 2, 6, 8, 7},
        {7, 10}
    };
    vector<string> res = Solution().computeSimilarities(docs);
    for (auto &r : res) {
        cout << r << endl;
    }
	return 0;
}