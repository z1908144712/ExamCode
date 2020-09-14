#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    map<vector<double>, set<vector<int>>> m;
    map<vector<int>, int> r;
    int maxPoints(vector<vector<int>>& points) {
        int realLen = points.size();
        for (int i = 0; i < points.size(); i++) {
            if (r.count(points[i])) {
                r[points[i]]++;
                points.erase(points.begin() + i);
                i--;
            } else {
                r.insert(make_pair(points[i], 1));
            }
        }
        int len = points.size();
        if (len <= 2) {
            return realLen;
        }
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {
                vector<double> line = getLine(points[i], points[j]);
                //cout << i << " " << j << " " << line[0] << " " << line[1] << " " << line[2] << endl;
                set<vector<int>> s;
                if (m.count(line)) {
                    map<vector<double>, set<vector<int>>>::iterator it = m.find(line);
                    s = it->second;
                    if (!s.count(points[j])) {
                        s.insert(points[j]);
                        it->second = s;
                    }
                } else {
                    s = { points[i], points[j] };
                    m.insert(make_pair(line, s));
                }
            }
        }
        int max = 0;
        for (pair<vector<double>, set<vector<int>>> p : m) {
            int size = p.second.size();
            for (vector<int> point : p.second) {
                if (r[point] > 1) {
                    size += r[point] - 1;
                }
            }
            if (size > max) {
                max = size;
            }
        }
        return max;
    }

    vector<double> getLine(vector<int> &x, vector<int> &y) {
        int kx = y[1] - x[1], ky = y[0] - x[0];
        double Kx, Ky, Y;
        if (ky == 0) {
            Kx = 1;
            Ky = 0;
            Y = x[0];
        } else {
            if (kx == 0) {
                Kx = 0;
                Ky = 1;
            } else {
                int k = gcd(kx, ky);
                Kx = kx / k;
                Ky = ky / k;
                if (Kx > 0 && Ky < 0 || Kx < 0 && Ky < 0) {
                    Kx = -Kx;
                    Ky = -Ky;
                }
            }
            Y = x[1] - Kx / Ky * x[0];
        }
        return {Kx, Ky, Y};
    }

    int gcd(int a, int b) {
        int max = a > b ? a : b;
        int min = a < b ? a : b;
        int tmp;
        while (max % min != 0) {
            tmp = min;
            min = max % min;
            max = tmp;
        }
        return min;
    }
};

int main() {
    Solution sol;
    //vector<vector<int>> points = { {0, 0}, {0, 0}};
    //vector<vector<int>> points = { {1, 1}, {1, 1} ,{1, 1} };
    //vector<vector<int>> points = { {0, 0}, {1, 1} ,{0, 0} };
    //vector<vector<int>> points = { { 4, 0 }, { 4, -1 }, { 4, 5 } };
    //vector<vector<int>> points = {{1, 1}, {2, 2}, {3, 3}};
    //vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    //vector<vector<int>> points = { { 0, 0 }, { 94911151, 94911150 }, { 94911152, 94911151 } };
    vector<vector<int>> points = {{15, 12}, {9, 10}, {-16, 3}, {-15, 15}, {11, -10}, {-5, 20}, {-3, -15}, {-11, -8}, {-8, -3}, {3, 6}, {15, -14}, {-16, -18}, {-6, -8}, {14, 9}, {-1, -7}, {-1, -2}, {3, 11}, {6, 20}, {10, -7}, {0, 14}, {19, -18}, {-10, -15}, {-17, -1}, {8, 7}, {20, -18}, {-4, -9}, {-9, 16}, {10, 14}, {-14, -15}, {-2, -10}, {-18, 9}, {7, -5}, {-12, 11}, {-17, -6}, {5, -17}, {-2, -20}, {15, -2}, {-5, -16}, {1, -20}, {19, -12}, {-14, -1}, {18, 10}, {1, -20}, {-15, 19}, {-18, 13}, {13, -3}, {-16, -17}, {1, 0}, {20, -18}, {7, 19}, {1, -6}, {-7, -11}, {7, 1}, {-15, 12}, {-1, 7}, {-3, -13}, {-11, 2}, {-17, -5}, {-12, -14}, {15, -3}, {15, -11}, {7, 3}, {19, 7}, {-15, 19}, {10, -14}, {-14, 5}, {0, -1}, {-12, -4}, {4, 18}, {7, -3}, {-5, -3}, {1, -11}, {1, -1}, {2, 16}, {6, -6}, {-17, 9}, {14, 3}, {-13, 8}, {-9, 14}, {-5, -1}, {-18, -17}, {9, -10}, {19, 19}, {16, 7}, {3, 7}, {-18, -12}, {-11, 12}, {-15, 20}, {-3, 4}, {-18, 1}, {13, 17}, {-16, -15}, {-9, -9}, {15, 8}, {19, -9}, {9, -17}};
    cout << sol.maxPoints(points) << endl;
    return 0;
}