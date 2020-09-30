#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;



class Solution {
public:
    unordered_set<int> st;
    unordered_map<int, unordered_set<int>> mp;
    bool backtrace(int start, int target) {
        if (start == target) {
            return true;
        }
        for (auto &v : mp[start]) {
            if (!st.count(v)) {
                st.insert(v);
                bool r = backtrace(v, target);
                if (r) {
                    return r;
                }
                st.erase(v);
            }
        }
        return false;
    }

    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        for (int i = 0; i < graph.size(); i++) {
            mp[graph[i][0]].insert(graph[i][1]);
        }
        st.insert(start);
        return backtrace(start, target);
    }
};

int main() {
    vector<vector<int>> graph{ {0, 1} ,{0, 2},{0, 4},{0, 4},{0, 1},{1, 3},{1, 4},{1, 3},{2, 3},{3, 4} };
    cout << Solution().findWhetherExistsPath(5, graph,0 ,4) << endl;
	return 0;
}