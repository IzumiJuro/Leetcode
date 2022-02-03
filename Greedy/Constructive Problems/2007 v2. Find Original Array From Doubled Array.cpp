//
// Created by Cauchy on 2022/2/4.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        int n = changed.size();
        if (n & 1) return {};

        sort(changed.begin(), changed.end());

        vector<int> res;
        int left = 0, right = 0;
        vector<int> used(n);
        for (int i = 0; i < n/2; i++) {
            while (left < n && used[left])
                left++;
            if (left == n) return {};
            res.emplace_back(changed[left]);
            used[left] = 1;
            while (right < n && (used[right] || changed[right] != changed[left] * 2))
                right++;
            if (right == n) return {};
            used[right] = 1;
        }
        return res;
    }
};

