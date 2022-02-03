//
// Created by Cauchy on 2022/1/29.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, res = 0;
        for (auto ch: s) {
            if (ch == '(')
                count++;
            else
                count--;
            if (count < 0) {
                res++;
                count = 0;
            }
        }
        return count + res;
    }
};
