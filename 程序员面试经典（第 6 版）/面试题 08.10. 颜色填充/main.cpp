#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor) {
        if (sr >= image.size() || sc >= image[0].size()) {
            return;
        }
        if (image[sr][sc] == oldColor) {
            image[sr][sc] = newColor;
            dfs(image, sr + 1, sc, oldColor, newColor);
            dfs(image, sr - 1, sc, oldColor, newColor);
            dfs(image, sr, sc + 1, oldColor, newColor);
            dfs(image, sr, sc - 1, oldColor, newColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] != newColor) {
            dfs(image, sr, sc, image[sr][sc], newColor);
        }
        return image;
    }
};

int main() {
    vector<vector<int>> image{ {1,1,1} ,{1,1,0},{1,0,1} };
    for (auto &item : Solution().floodFill(image, 1, 1, 2)) {
        for (auto &it : item) {
            cout << it << " ";
        }
        cout << endl;
    }
	return 0;
}