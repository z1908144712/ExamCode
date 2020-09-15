#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

int minDistance(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
        dp[i][0] = i; 
    for (int j = 1; j <= n; j++)
        dp[0][j] = j; 
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = min({
                    dp[i - 1][j] + 1, 
                    dp[i][j - 1] + 1, 
                    dp[i - 1][j - 1] + 1 }); 
    return dp[m][n];
}

int main() {
	string noword, A, B;
	getline(cin, noword);
	getline(cin, A);
	getline(cin, B);
    stringstream ss(noword);
    string s;
    size_t it;
    while (getline(ss, s, ' ')) {
        while ((it = A.find(s)) != string::npos) {
            A = A.substr(0, it) + A.substr(it+s.size());
        }
        while ((it = B.find(s)) != string::npos) {
            B = B.substr(0, it) + B.substr(it+s.size());
        }
    }
    cout << minDistance(A, B) << endl;
	return 0;
}

/*
hello ,
I am a coder
hello ,  I am a singer

*/