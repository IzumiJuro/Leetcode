//
// Created by Cauchy on 2022/2/10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int> &nums) {
        int n = nums.size();

        int p = 1, q = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                q = p + 1;
            else if (nums[i] > nums[i - 1])
                p = q + 1;
        }
        return max(p, q);
    }
};