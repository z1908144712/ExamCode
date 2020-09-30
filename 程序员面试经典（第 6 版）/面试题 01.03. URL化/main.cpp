#include <iostream>

using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        string res;
        for (int i = 0; i < length; i++) {
            if (S[i] == ' ') {
                res.append("%20");
            } else {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};

int main() {
    cout << Solution().replaceSpaces("Mr John Smith    ", 13) << endl;
	return 0;
}