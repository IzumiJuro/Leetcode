//
// Created by Cauchy on 2022/2/12.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> Father;
public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size();

        for (int i = 0; i < n; i++)
            Father[i] = i;

        for (auto x: allowedSwaps) {
            int a = x[0];
            int b = x[1];
            if (FindSet(a) != FindSet(b))
                Union(a, b);
        }

        unordered_map<int, vector<int>> Map;
        for (int i = 0; i < n; i++)
            Map[FindSet(i)].emplace_back(i);

        int count = 0;

        for (auto x: Map) {
            multiset<int> Set;
            for (auto i: x.second)
                Set.insert(source[i]);
            for (auto i: x.second) {
                if (Set.find(target[i]) != Set.end())
                    Set.erase(Set.lower_bound(target[i]));
            }
            count += Set.size();
        }
        return count;

    }

    int FindSet(int x) {
        if (x == Father[x])
            return Father[x];
        return Father[x] = FindSet(Father[x]);
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x <= y)
            Father[y] = x;
        else
            Father[x] = y;
    }
};