#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string compressString(string S) {
        string r;
        int cnt;
        char ch = 0;
        for (auto & c : S) {
            if (ch == 0) {
                ch = c;
                cnt = 1;
            } else if (ch == c) {
                cnt++;
            } else {
                r.push_back(ch);
                r.append(to_string(cnt));
                ch = c;
                cnt = 1;
            }
        }
        r.push_back(ch);
        r.append(to_string(cnt));
        return r.size() < S.size() ? r : S;
    }
};

int main() {
    cout << Solution().compressString("rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff") << endl;
	return 0;
}