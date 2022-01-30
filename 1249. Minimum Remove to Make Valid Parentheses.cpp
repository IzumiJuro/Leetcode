//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0;
        int right = count(begin(s), end(s), ')');
        string ans;
        for (auto &ch: s) {
            if (ch == '(') {
                if (right > 0) {
                    ans += ch;
                    left++;
                    right--;
                }
            } else if (ch == ')') {
                if (left > 0) {
                    ans += ch;
                    left--;
                } else {
                    right--;
                }
            } else ans += ch;
        }
        return ans;
    }
};
