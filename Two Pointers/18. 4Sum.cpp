#include <bits/stdc++.h>
using LL = long long;
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if ((LL)nums[i] * 4 > target) break;
            if ((LL)nums[i] + (LL)nums.back() * 3 < target) continue;

            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if ((LL)nums[i] + (LL)nums[j] * 3 > target) break;
                if ((LL)nums[i] + (LL)nums[j] + (LL)nums.back() * 2 < target) continue;

                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = nums.size() - 1;
                if ((LL)nums[i] + (LL)nums[j] + (LL)nums[left] * 2 > target) break;

                while (left < right) {
                    LL sum = 0LL + nums[i] + nums[j] + nums[left] + nums[right]; 
                    if (sum == target) {
                        vector<int> temp{nums[i], nums[j], nums[left], nums[right]};
                        res.emplace_back(temp);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                    else if (sum < target)
                        left++;
                    else if (sum > target)
                        right--;
                }
            }
        }
        return res;
    }
};
