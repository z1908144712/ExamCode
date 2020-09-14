#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 0) {
            return true;
        }
        return verifyPostorderHelper(postorder, 0, postorder.size() - 1);
    }

    bool verifyPostorderHelper(vector<int>& postorder, int left, int right) {
        if (left >= right) {
            return true;
        }
        int left_child = left;
        while (left_child < right && postorder[left_child] < postorder[right]) {
            left_child++;
        }
        int l = left_child;
        while (l < right) {
            if (postorder[l++] < postorder[right]) {
                return false;
            }
        }
        return verifyPostorderHelper(postorder, left, left_child - 1) && verifyPostorderHelper(postorder, left_child, right - 1);
    }
};

int main() {
    vector<int> postorder = { 1,3,2,6,5 };
    cout << Solution().verifyPostorder(postorder) << endl;
    return 0;
}