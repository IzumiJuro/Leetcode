#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res;
        sort(nums.begin(), nums.end());
        int temp = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int sum = target - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (temp > abs(nums[left] + nums[right] - sum)) {
                    temp = abs(nums[left] + nums[right] - sum);
                    res = nums[left] + nums[right] + nums[i];
                }
                if (nums[left] + nums[right] == sum)
                    return target;
                else if (nums[left] + nums[right] < sum)
                    left++;
                else
                    right--;
            }
        }
        return res;
    }
};