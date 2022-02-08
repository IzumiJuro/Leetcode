//
// Created by Cauchy on 2022/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        vector<int> sold(k + 1, 0);
        vector<int> hold(k + 1, INT_MIN);
        for (auto &p: prices) {
            for (int i = 1; i <= k; i++) {
                hold[i] = max(hold[i], sold[i - 1] - p);
                sold[i] = max(sold[i], hold[i] + p);
            }
        }
        return sold[k];
    }
};