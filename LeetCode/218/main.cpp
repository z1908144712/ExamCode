#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<pair<int, int>> all;
        vector<vector<int>> res;
        for (auto &building : buildings) {
            all.insert(make_pair(building[0], -building[2]));
            all.insert(make_pair(building[1], building[2]));
        }
        multiset<int> heights = {0};
        int prev = 0;
        for (auto &p : all) {
            if (p.second < 0) {
                heights.insert(-p.second);
            } else {
                heights.erase(heights.find(p.second));
            }
            int maxHeight = *(heights.rbegin());
            if (prev != maxHeight) {
                prev = maxHeight;
                res.push_back({p.first, maxHeight});
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> buildings = { {2, 9, 10} ,{3, 7, 15},{5, 12, 12},{15, 20, 10},{19, 24, 8} };
    vector<vector<int>> res = sol.getSkyline(buildings);
    for (auto &k : res) {
        cout << k[0] << " " << k[1] << endl;
    }
    return 0;
}