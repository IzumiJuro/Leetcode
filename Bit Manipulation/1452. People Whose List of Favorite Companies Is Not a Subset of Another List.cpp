//
// Created by Cauchy on 2022/2/6.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies) {
        int n = favoriteCompanies.size();
        unordered_map<string, bitset<100>> Map;
        for (int i = 0; i < n; i++) {
            bitset<100> bs;
            bs.set(i);
            for (auto &c: favoriteCompanies[i]) {
                Map[c] |= bs;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            bitset<100> bs;
            bs.set();
            for (auto &c: favoriteCompanies[i]) {
                bs &= Map[c];
            }
            if (bs.count() == 1)
                res.emplace_back(i);
        }
        return res;
    }
};