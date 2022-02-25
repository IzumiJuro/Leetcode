#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return 1;
            
        int left = 1;
        int right = 2;

        while (right < nums.size()) {
            if (nums[right] == nums[left] && nums[right] == nums[left-1])
                right++;
            else {
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        return left + 1;
    }
};