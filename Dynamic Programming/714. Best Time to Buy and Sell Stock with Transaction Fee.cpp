//
// Created by Cauchy on 2022/2/9.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
//        int dp[n][2];
//        dp[0][0] = 0;
//        dp[0][1] = -prices[0];
//        for (int i = 1; i < n; i++) {
//            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
//            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
//        }
//        return dp[n-1][0];
        int hold = INT_MIN, sold = 0;
        for (auto p: prices) {
            int hold_temp = hold, sold_temp = sold;
            hold = max(hold, sold_temp - p);
            sold = max(sold, hold + p - fee);
        }
        return sold;
    }
};