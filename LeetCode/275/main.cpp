#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        for (int i = 0; i < citations.size(); i++) {
            if (citations.size() - i <= citations[i]) {
                return citations.size() - i;
            }
        }
        return 0;
    }
};

int main() {
    vector<int> citations = { 3,0,6,1,5 };
    cout << Solution().hIndex(citations) << endl;
    return 0;
}