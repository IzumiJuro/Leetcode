//
// Created by Cauchy on 2022/2/3.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> ans;
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) {

        int len = nums.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += nums[i] - nums[0];
        ans.emplace_back(sum);

        for (int i = 1; i < len; i++) {
            sum += i * (nums[i] - nums[i - 1]);
            sum -= (len - i) * (nums[i] - nums[i - 1]);
            ans.emplace_back(sum);
        }
        return ans;
    }
};