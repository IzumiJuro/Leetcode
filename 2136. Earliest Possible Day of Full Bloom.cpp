//
// Created by Cauchy on 2022/1/29.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        unsigned int n = plantTime.size();

        vector<int> order(n);
        for (int i = 0; i < n; ++i) {
            order[i] = i;
        }
        //使用lambda进行排序
        //捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）
        sort(order.begin(), order.end(), [&](int i, int j) {
            return growTime[i] > growTime[j];
        });

        int ans = 0, days = 0;
        for (auto i: order) {
            days += plantTime[i];
            ans = max(ans, days+growTime[i]);
        }
        return ans;
    }
};

