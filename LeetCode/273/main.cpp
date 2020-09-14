#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string r = "";
        vector<string> zeroNums = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> oneNums = {"Ten", "Eleven", "Twelve", "Thirteen" , "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> twoNums = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> otherNums = {"Hundred", "Thousand", "Million", "Billion"};
        vector<int> nums;
        bool million = false, thousand = false;
        int n = num;
        while (n) {
            nums.push_back(n % 10);
            n /= 10;
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            string t = "";
            if (i == 9 && nums[i] != 0) {
                t = zeroNums[nums[i]] + " " + otherNums[3];
            } else if (i > 6 && nums[i] != 0) {
                million = true;
                if (i - 6 == 2) {
                    t = zeroNums[nums[i]] + " " + otherNums[0];
                } else {
                    if (nums[i] > 1) {
                        t = twoNums[nums[i] - 2];
                    } else {
                        t = oneNums[nums[--i]] + " " + otherNums[2];
                    }
                }
            } else if (i == 6) {
                if (nums[i] != 0) {
                    t = zeroNums[nums[i]] + " " + otherNums[2];
                } else {
                    if (million) {
                        t = otherNums[2];
                    }
                }
            } else if (i > 3 && nums[i] != 0) {
                thousand = true;
                if (i - 3 == 2) {
                    t = zeroNums[nums[i]] + " " + otherNums[0];
                } else {
                    if (nums[i] > 1) {
                        t = twoNums[nums[i] - 2];
                    } else {
                        t = oneNums[nums[--i]] + " " + otherNums[1];
                    }
                }
            } else if (i == 3) {
                if (nums[i] != 0) {
                    t = zeroNums[nums[i]] + " " + otherNums[1];
                } else {
                    if (thousand) {
                        t = otherNums[1];
                    }
                }
            } else if (i > 0 && nums[i] != 0){
                if (i == 2) {
                    t = zeroNums[nums[i]] + " " + otherNums[0];
                } else {
                    if (nums[i] > 1) {
                        t = twoNums[nums[i] - 2];
                    } else {
                        i--;
                        t = oneNums[nums[i]];
                    }
                }
            } else if (i == 0 && nums[i] != 0) {
                t = zeroNums[nums[i]];
            }
            if (!t.empty()) {
                if (r.empty()) {
                    r = t;
                } else {
                    r += " " + t;
                }
            }
        }
        return r;
    }
};

int main() {
    cout << Solution().numberToWords(100000) << endl;
    return 0;
}