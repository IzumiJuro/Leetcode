//
// Created by Cauchy on 2022/2/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
        bitset<20000> f;
        for (auto x: baseCosts)
            f[x] = true;

        for (auto x: toppingCosts)
            f |= (f << x | f << x * 2);

        int ans = INT_MAX;
        for (int i = 0; i < 20000; i++) {
            if (f[i] && abs(i - target) < abs(ans - target))
                ans = i;
        }
        return ans;
    }
};