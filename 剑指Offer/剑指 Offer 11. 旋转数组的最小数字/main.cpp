#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minArray(vector<int>& numbers) {
        // int i = 0;
        // while ( i + 1 < numbers.size() && numbers[i] <= numbers[i + 1]) {
        //     i++;
        // }
        // if (i == numbers.size() - 1) {
        //     return numbers[0];
        // }
        // return numbers[i + 1];
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};

int main() {
    vector<int> numbers = { 2,2,2 };
    cout << Solution().minArray(numbers) << endl;
    return 0;
}