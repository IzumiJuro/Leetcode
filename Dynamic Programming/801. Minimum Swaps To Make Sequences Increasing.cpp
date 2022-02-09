//
// Created by Cauchy on 2022/2/10.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        int changed = 1, unchanged = 0;
        for (int i = 1; i < nums1.size(); i++) {
            int prev_changed = changed;
            int prev_unchanged = unchanged;

            unchanged = INT_MAX, changed = INT_MAX;
            if (nums1[i - 1] < nums1[i] && nums2[i - 1] < nums2[i]) {
                unchanged = min(unchanged, prev_unchanged);
                changed = min(changed, prev_changed + 1);
            }
            if (nums1[i - 1] < nums2[i] && nums2[i - 1] < nums1[i]) {
                unchanged = min(unchanged, prev_changed);
                changed = min(changed, prev_unchanged + 1);
            }

        }
        return min(changed, unchanged);
    }
};