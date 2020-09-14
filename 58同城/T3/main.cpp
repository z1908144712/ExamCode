#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param nums int整型一维数组 
     * @param numsLen int nums数组长度
     * @return int整型
     */
    int firstMissingPositive(int* nums, int numsLen) {
        // write code here
        set<int> st;
        for (int i = 0; i < numsLen; i++) {
            if (nums[i] > 0) {
                st.insert(nums[i]);
            }
        }
        int i = 1;
        for (; i <= st.size(); i++) {
            if (st.count(i) == 0){
                return i;                
            }
        }
        return i;
    }
};

int main() {
	return 0;
}