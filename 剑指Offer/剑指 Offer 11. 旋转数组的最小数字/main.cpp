#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int i = 0;
        while ( i + 1 < numbers.size() && numbers[i] <= numbers[i + 1]) {
            i++;
        }
        if (i == numbers.size() - 1) {
            return numbers[0];
        }
        return numbers[i + 1];
    }
};

int main() {
    vector<int> numbers = { 2,2,2 };
    cout << Solution().minArray(numbers) << endl;
    return 0;
}