#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int len = INT_MAX;

        for (right = 0; right < nums.size(); right++) {
            sum += nums[right];

            if (sum < target)
                continue;
            else {
                while (sum >= target) {
                    len = min(len, right - left + 1);
                    sum -= nums[left++];
                }
            }
        }

        return len == INT_MAX ? 0 : len;
    }
};