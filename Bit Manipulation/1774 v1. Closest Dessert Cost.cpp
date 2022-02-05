//
// Created by Cauchy on 2022/2/5.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        vector<int> TOP;
        for (auto x: toppingCosts) {
            TOP.emplace_back(x);
            TOP.emplace_back(x);
        }

        bitset<20005> B(1);

        for (int i = 0; i < TOP.size(); i++) {
            bitset<20005> temp = B;

            temp <<= TOP[i];

            B |= temp;
        }
        int dif = INT_MAX;
        int ans = INT_MAX;
        for (auto x: baseCosts) {
            if (abs(x - target) == dif)
                ans = min(ans, x);

            if (abs(x - target) < dif) {
                dif = abs(x - target);
                ans = x;
            }

            for (int i = 1; i < 20005; i++) {
                if (B[i] == 1) {
                    if (abs(i + x - target) == dif)
                        ans = min(ans, i + x);
                    if (abs(i + x - target) < dif) {
                        dif = abs(i + x - target);
                        ans = i + x;
                    }
                }
            }
        }
        return ans;
    }
};