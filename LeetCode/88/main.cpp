#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if (m == 0) {
			for (size_t i = 0; i < n; i++) {
				nums1[i] = nums2[i];
			}
		}
		size_t i = 0;
		for (size_t j = 0; j < n; j++) {
			while (i < m && nums2[j] >= nums1[i]) {
				i++;
			}
			for (size_t k = m++; k > i; k--) {
				nums1[k] = nums1[k-1];
			}
			nums1[i++] = nums2[j];
		}
	}
};

int main() {
	Solution s;
	vector<int> nums1 = { 4,5,6,0,0,0 };
	vector<int> nums2 = { 1,2,3 };
	s.merge(nums1, 3, nums2, 3);
	for (size_t i = 0; i < nums1.size(); i++) {
		cout << nums1[i] << " ";
	}
	cout << endl;
	return 0;
}