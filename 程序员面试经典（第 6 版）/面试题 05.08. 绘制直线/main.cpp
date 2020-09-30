#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> drawLine(int length, int w, int x1, int x2, int y) {
        vector<int> res(length, 0);
        int offset = y * (w / 32);
        int head = x1 / 32 + offset;
        int rear = x2 / 32 + offset;
        for (int i = head; i <= rear; i++) {
            res[i] = -1;
        }
        res[head] = (uint32_t)res[head] >> (x1 % 32);
        res[rear] = (uint32_t)res[rear] & (INT_MIN >> (x2 % 32));
        return res;
    }
};

int main() {
    for (auto &i : Solution().drawLine(1, 32, 30, 31, 0)) {
        cout << i << " ";
    }
	return 0;
}