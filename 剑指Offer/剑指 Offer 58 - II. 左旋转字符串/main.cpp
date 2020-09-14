#include <iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (n == s.size()) {
            return s;
        }
        return s.substr(n) + s.substr(0, n);
    }
};

int main() {
    string s = "lrloseumgh";
    int n = 6;
    cout << Solution().reverseLeftWords(s, n) << endl;
	return 0;
}