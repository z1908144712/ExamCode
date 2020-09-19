#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    	if (n == 0) {
    		return {};
    	}
    	if (n == 1) {
    		return {0};
    	}
    	vector<int> res;
        vector<int> degree(n);
    	vector<vector<int>> list(n);
    	for (int i = 0; i < edges.size(); i++) {
    		degree[edges[i][0]]++;
    		degree[edges[i][1]]++;
    		list[edges[i][0]].push_back(edges[i][1]);
    		list[edges[i][1]].push_back(edges[i][0]);
    	}
    	queue<int> que;
        for (int i = 0; i < degree.size(); i++) {
	        if (degree[i] == 1) {
		        que.push(i);
	        }
        }
    	int num = 0;
    	while (!que.empty()) {
    		int len = que.size();
    		if (n - num == 1 || n - num == 2) {
    			res.push_back(que.front());
    			que.pop();
    			continue;
    		}
    		for (int i = 0; i < len; i++) {
    			int idx = que.front();
    			que.pop();
    			num++;
    			while (!list[idx].empty()) {
    				if (--degree[list[idx][0]] == 1) {
    					que.push(list[idx][0]);
    				}
    				list[idx].erase(list[idx].begin());
    			}
    		}
    	}
    	return res;
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges ={{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
	vector<int> r = Solution().findMinHeightTrees(n, edges);
	for (auto & i : r) {
		cout << i << " ";
	}
	return 0;
}