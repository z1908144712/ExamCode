#include <ctime>
#include <iostream>

using namespace std;

int rand7() {
    srand(time(nullptr));
    return rand() % 7 + 1;
}

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();
        while (a == 7) {
            a = rand7();
        }
        while (b > 5) {
            b = rand7();
        }
        return (a%4 == 0 ? 0:5) + b;
    }
};

int main() {
    cout << Solution().rand10() << endl;
	return 0;
}