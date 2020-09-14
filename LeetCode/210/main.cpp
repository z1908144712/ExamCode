#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> edges;
    //0:Î´ËÑË÷ 1:ËÑË÷ÖÐ 2:ÒÑËÑË÷
    vector<int> visited, stack;
    bool invaild = false;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for (int i = 0; i < numCourses && !invaild; i++) {
            dfs(i);
        }
        if (invaild) {
            return {};
        }
        reverse(stack.begin(), stack.end());
        return stack;
    }

    void dfs(int a) {
        if (visited[a] == 2) {
            return;
        }
        if (visited[a] == 1) {
            invaild = true;
            return;
        }
        visited[a] = 1;
        for (int i : edges[a]) {
            dfs(i);
            if (invaild) {
                return;
            }
        }
        visited[a] = 2;
        stack.push_back(a);
    }
};

int main() {
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> r = sol.findOrder(numCourses, prerequisites);
    for (int t : r) {
        cout << t << " ";
    }
    return 0;
}