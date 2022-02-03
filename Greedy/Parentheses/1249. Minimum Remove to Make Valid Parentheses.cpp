//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0; // 统计碰到的左括号
        int right = count(begin(s), end(s), ')'); //统 计字符串s中有多少右括号
        string ans;
        for (auto &ch: s) {
            if (ch == '(') {
                if (right > 0) { // 当碰到左括号且有多余的右括号和它配对
                    ans.push_back(ch);
                    left++;
                    right--;
                }
            } else if (ch == ')') {
                if (left > 0) { // 有多余的左括号和它配对
                    ans.push_back(ch);
                    left--;
                } else { // 无法配对的右括号需要删除
                    right--;
                }
            } else ans.push_back(ch);// 保留字母
        }
        return ans;
    }
};
