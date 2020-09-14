#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size());
        return mergeSort(nums, tmp, 0, nums.size() - 1);
    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int L, int R) {
        if (L >= R) {
            return 0;
        }
        int mid = (L + R) / 2;
        int cnt = mergeSort(nums, tmp, L, mid) + mergeSort(nums, tmp, mid + 1, R);
        int i = L, j = mid + 1, pos = L;
        while (i <= mid && j <= R) {
            if (nums[i] <= nums[j]) {
                tmp[pos++] = nums[i++];
                cnt += j - mid - 1;
            } else {
                tmp[pos++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[pos++] = nums[i++];
            cnt += j - mid - 1;
        }
        while (j <= R) {
            tmp[pos++] = nums[j++];
        }
        copy(tmp.begin() + L, tmp.begin() + R + 1, nums.begin() + L);
        return cnt;
    }
};

int main() {
    vector<int> nums = { 7,5,6,4 };
    cout << Solution().reversePairs(nums) << endl;
    return 0;
}