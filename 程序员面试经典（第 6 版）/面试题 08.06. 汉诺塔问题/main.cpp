#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
		move(A.size(), A, B, C);
    }

	void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
	    if (n == 1) {
		    C.push_back(A.back());
	    	A.pop_back();
	    	return;
	    }
    	move(n - 1, A, C, B);
    	C.push_back(A.back());
    	A.pop_back();
    	move(n - 1, B, A, C);
    }
};

int main() {
    vector<int> A{2, 1, 0}, B, C;
	Solution().hanota(A, B, C);
	for (auto &i : C) {
		cout << i << " ";
	}
	return 0;
}