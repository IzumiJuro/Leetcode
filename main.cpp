//
// Created by Cauchy on 2022/1/30.
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
int main() {
    Solution solution;
    vector<int>  s = {1,3,4,2,6,8};
    solution.findOriginalArray(s);
}