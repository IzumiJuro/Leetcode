////
//// Created by Cauchy on 2022/2/8.
////
//#include <bits/stdc++.h>
//
//using namespace std;
//
//class Solution {
//public:
////    int maxProduct(string s) {
////        int n = s.size();
////        int res = 0;
////        int all = (1 << n) - 1;
////        for (int subset = 1; subset < all; subset++) {
////            res = max(res, lp(s, subset) * lp())
////        }
////    }
////
////    int lp(string &s, int state) {
////        string t;
////        for (int i = 0; i < s.size(); i++) {
////            if ((state >> i) & 1)
////                t.push_back(s[s.size() - 1 - i]);
////        }
////
////        int n = t.size();
////        vector<vector<int>> dp(n, vector<int>(n, 0));
////        for (int len = 2; len <= n; len++) {
////            for (int i = 0; i + len - 1 < n; i++) {
////                int j = i + len - 1;
////                if (t[i] == t[j])
////                    dp[i][j] = dp[i + 1][j - 1] + 2;
////                else
////                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
////            }
////        }
//    }
//};