//
// Created by Cauchy on 2022/2/4.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> recoverArray(vector<int> &nums) {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());

        for (int i = 1; i <= n; i++) {
            if (nums[i] == nums[0]) continue;
            if ((nums[i] - nums[0]) & 1) continue;
            int k = (nums[i] - nums[0]) / 2;

            int left = 0, right = 0;
            vector<int> res;
            vector<int> visited(2 * n, 0);
            int flag = 1;
            for (int j = 0; j < n; j++) {
                while (left < 2 * n && visited[left] == 1)
                    left++;
                if (left == 2 * n) {
                    flag = 0;
                    break;
                }
                visited[left] = 1;
                while (right < 2 * n && (nums[right] != nums[left] + 2 * k || visited[right] == 1))
                    right++;
                if (right < 2 * n) {
                    res.emplace_back(nums[left] + k);
                    visited[right] = 1;
                } else {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                return res;
        }
        return {};
    }
};