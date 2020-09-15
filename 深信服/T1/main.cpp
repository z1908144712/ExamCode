#include <iostream>
#include <vector>

using namespace std;

int main() {
	int w, l;
	cin >> w >> l;
	vector<int> arr(l+1);
    arr[0] = 100;
	for (int i = 1; i < l + 1; i++) {
		cin >> arr[i];
        arr[i] = 100 - arr[i];
	}
    l = l + 1;
    int ans = 0;
    for (int i = 1; i < l - 1; i++) {
        int leftMax = 0, rightMax = 0;
        // 找右边最高的柱子
        for (int j = i; j < l; j++) {
            rightMax = max(arr[j], rightMax);
        }
        // 找左边最高的柱子
        for (int j = i; j >= 0; j--) {
            leftMax = max(arr[j], leftMax);
        }
        // 如果自己就是最高的话，
        // leftMax == rightMax == height[i]
        ans += min(leftMax, rightMax) - arr[i];
    }
    //int right = l - 1;
    //int rightMax = arr[l - 1];
    //while (right >= 0) {
    //    if (arr[right] > rightMax) {
    //        rightMax = arr[right];
    //        break;
    //    }
    //    right--;
    //}
    //int left = 0;
    //int leftMax = arr[0];
    //while (left < l) {
    //    if (arr[left] > leftMax) {
    //        leftMax = arr[left];
    //        break;
    //    }
    //    left++;
    //}
    //ans += rightMax - arr[l-1] + leftMax - arr[0];
    cout << ans * w << endl;
	return 0;
}

/*
2 5
4 3 4 5 3
*/