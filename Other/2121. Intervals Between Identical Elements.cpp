//
// Created by Cauchy on 2022/2/3.
//
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
class Solution {
public:
    vector<long long> getDistances(vector<int> &arr) {
        int n = arr.size();
        vector<LL> res(n, 0);
        unordered_map<int, vector<int>> Map;

        for (int i = 0; i < n; ++i) {
            Map[arr[i]].emplace_back(i);
        }
//        arr = [2,1,3,1,2,3,3]
//        2: 0, 4
//        1: 1, 3
//        3: 2, 5, 6
        for (auto& [val, pos]: Map) {
            for (auto x: pos)
                res[pos[0]] += x - pos[0];
            int len = pos.size();
            for (int i = 1; i < len; i++)
                res[pos[i]] = res[pos[i - 1]] + i * (pos[i] - pos[i - 1]) - (len - i) * (pos[i] - pos[i - 1]);
        }
        return res;
    }
};