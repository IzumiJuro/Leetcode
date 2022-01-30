//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;
        for (auto &ch: s) {
            if (ch == '(') {
                left++;
                if (right & 1) {
                    ans++;
                    right = 0;
                    left--;
                }
            } else {
                right++;
                if (left == 0) {
                    left++;
                    ans++;
                }
                if (right == 2 && left > 0) {
                    left--;
                    right = 0;
                }
            }
        }
        return ans + 2*left - right;
    }
};

