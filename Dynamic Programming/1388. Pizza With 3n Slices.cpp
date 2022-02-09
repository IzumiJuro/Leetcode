//
// Created by Cauchy on 2022/2/10.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSizeSlices(vector<int> &slices) {
        int n = slices.size() / 3;
        auto l1 = vector<int>(slices.begin(), slices.end() - 1);
        auto l2 = vector<int>(slices.begin() + 1, slices.end());
        return max(slice_helper(l1), slice_helper(l2));
    }

    int slice_helper(vector<int> &s) {
        int n = s.size();
        int m = (n + 1) / 3;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[1][1] = s[0];
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int choose = dp[i - 2][j - 1] + s[i - 1];
                int not_choose = dp[i - 1][j];
                dp[i][j] = max(choose, not_choose);
            }
        }
        return dp[n][m];
    };
};