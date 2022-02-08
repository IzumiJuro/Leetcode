//
// Created by Cauchy on 2022/2/9.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int hold = INT_MIN, sold = 0, sold_cd = 0;
        for (auto p: prices) {
            int pre_sold = sold;
            hold = max(hold, sold_cd - p);
            sold = hold + p;
            sold_cd = max(sold_cd, pre_sold);
        }
        return max(sold, sold_cd);
    }
};

