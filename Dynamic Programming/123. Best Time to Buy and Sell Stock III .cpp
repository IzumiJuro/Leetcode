//
// Created by Cauchy on 2022/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
//        vector<vector<int>> dp(n+1, vector<int>(4));
//        dp[0][1] = dp[0][3] = 0;
//        dp[0][0] = dp[0][2] = -prices[0];
//        for (int i = 1; i < n; i++) {
//            dp[i][0] = max(dp[i-1][0], -prices[i]);
//            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
//            dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]);
//            dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i]);
//        }
//        return max(dp[n-1][1], dp[n-1][3]);
        int hold1, hold2, sold1, sold2;
        hold1 = hold2 = -prices[0];
        sold1 = sold2 = 0;
        for (int i = 1; i < n; i++) {
            hold1 = max(hold1, -prices[i]);
            sold1 = max(sold1, hold1 + prices[i]);
            hold2 = max(hold2, sold1 - prices[i]);
            sold2 = max(sold2, hold2 + prices[i]);
        }
        return max(sold1, sold2);
    }
};