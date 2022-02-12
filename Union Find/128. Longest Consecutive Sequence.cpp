//
// Created by Cauchy on 2022/2/12.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> parent;
public:
    int longestConsecutive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            parent[nums[i]] = nums[i];
            if (parent.find(nums[i] - 1) != parent.end() && FindSet(nums[i] - 1) != FindSet(nums[i]))
                Union(nums[i] - 1, nums[i]);
            if (parent.find(nums[i] + 1) != parent.end() && FindSet(nums[i] + 1) != FindSet(nums[i]))
                Union(nums[i] + 1, nums[i]);
        }

        for (int i = 0; i < n; i++) {
            parent[nums[i]] = FindSet(nums[i]);
        }

        unordered_map<int, unordered_set<int>> Map;
        for (auto x: parent) {
            Map[x.second].emplace(x.first);
        }
        int res = 0;
        for (const auto &x: Map) {
            int n = x.second.size();
            res = max(res, n);
        }
        return res;


    }

    int FindSet(int x) {
        if (x == parent[x])
            return parent[x];
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int x, int y) {
        x = parent[x];
        y = parent[y];
        if (x <= y)
            parent[y] = x;
        else
            parent[x] = y;
    }
};