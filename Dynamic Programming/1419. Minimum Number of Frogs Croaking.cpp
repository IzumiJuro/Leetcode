//
// Created by Cauchy on 2022/2/10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int res = 0;
        int c = 0, r = 0, o = 0, a = 0;
        for (auto ch: croakOfFrogs) {
            if (ch == 'c')
                c++;
            else if (ch == 'r') {
                c--;
                r++;
                if (c < 0) return -1;
            } else if (ch == 'o') {
                r--;
                o++;
                if (r < 0) return -1;
            } else if (ch == 'a') {
                o--;
                a++;
                if (o < 0) return -1;
            } else if (ch == 'k') {
                a--;
                if (a < 0) return -1;
            }
            res = max(res, c + r + o + a);
        }
        if (c + r + o + a > 0) return -1;

        return res;
    }
};