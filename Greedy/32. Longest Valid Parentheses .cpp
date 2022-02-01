//
// Created by Cauchy on 2022/2/1.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        vector<int> stack(1, -1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                stack.emplace_back(i);
            else {
                stack.pop_back();
                if (stack.empty())
                    stack.emplace_back(i);
                else
                    res = max(res, i - stack.back());
            }
        }
        return res;
    }
};