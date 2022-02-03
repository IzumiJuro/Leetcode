//
// Created by Cauchy on 2022/2/4.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        sort(changed.begin(), changed.end());
        vector<int> ans;
        list<int> queue;
        for (auto x: changed) {
            if (!queue.empty() && x == queue.front())
                queue.pop_front();
            else {
                ans.emplace_back(x);
                queue.emplace_back(2*x);
            };
        }
        if (!queue.empty()) return {};
        return ans;
    }
};