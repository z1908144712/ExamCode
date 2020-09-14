#include <iostream>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        multiset<char> A, secretM, guessM;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                A.insert(secret[i]);
            } else {
                secretM.insert(secret[i]);
                guessM.insert(guess[i]);
            }
        }
        int B = 0;
        for (char c : guessM) {
            if (secretM.count(c)) {
                secretM.erase(secretM.find(c));
                B++;
            }
        }
        return to_string(A.size()) + "A" + to_string(B) + "B";
    }
};

int main() {
    string secret = "1807";
    string guess = "7810";
    cout << Solution().getHint(secret, guess) << endl;
    return 0;
}