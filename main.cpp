//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int ans = 1;
        int left = index;
        int right = index;
        int rest = maxSum - n;
        while (left > 0 && right < n - 1) {
            int len = right - left + 1;

            if (rest >= len) {
                rest -= len;
                ans++;
                left = max(0, left - 1);
                right = min(n - 1, right + 1);
            }
            else
                break;
        }
        ans += rest / n;
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> quantities{15,10,10};
    solution.maxValue(4, 2, 6);
}