//
// Created by Cauchy on 2022/2/8.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);


        int res1 = rob_helper(nums, 1, n);
        int res2 = rob_helper(nums, 0, n - 1);
        return max(res1, res2);
    }

    int rob_helper(vector<int> &nums, int start, int end) {
        int cur = nums[start], next = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; i++) {
            int temp = next;
            next = max(cur + nums[i], next);
            cur = temp;
        }
        return next;
    }
};