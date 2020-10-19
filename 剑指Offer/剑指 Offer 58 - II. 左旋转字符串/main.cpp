#include <iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n == s.size()) {
            return s;
        }
        for (int i = 0; i < (n >> 1); i++) {
            swap(s[i], s[n - i - 1]);
        }
        for (int i = n; i < ((s.size() + n) >> 1); i++) {
            swap(s[i], s[s.size() - i + n - 1]);
        }
        for (int i = 0; i < (s.size() >> 1); i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
        return s;
    }
};

int main() {
    string s = "lrloseumgh";
    int n = 6;
    cout << Solution().reverseLeftWords(s, n) << endl;
	return 0;
}