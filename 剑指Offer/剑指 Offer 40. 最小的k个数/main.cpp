#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == arr.size()) {
            return arr;
        }
        if (k == 0) {
            return {};
        }
        vector<int> r;
        priority_queue<int, vector<int> ,less<int>> pr;
        for (int i = 0; i < arr.size(); i++) {
            if (pr.size() < k) {
                pr.push(arr[i]);
            } else {
                if (arr[i] < pr.top()) {
                    pr.pop();
                    pr.push(arr[i]);
                }
            }
        }
        while (!pr.empty()) {
            r.push_back(pr.top());
            pr.pop();
        }
        return r;
    }
};

int main() {
    vector<int> arr = { 3,2,1};
    int k = 2;
    vector<int> r = Solution().getLeastNumbers(arr, k);
    for (auto &i : r) {
        cout << i << " ";
    }
    return 0;
}