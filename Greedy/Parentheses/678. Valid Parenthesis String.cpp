//
// Created by Cauchy on 2022/1/31.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int countMax = 0;
        int countMin = 0;
        for (auto ch: s) {
            if (ch == '(') {
                countMax++;
                countMin++;
            }
            else if (ch == ')') {
                countMax--;
                countMin--;
            }
            else {
                countMax++;
                countMin--;
            }
            if (countMin < 0)
                countMin = 0;
            if (countMax < 0)
                return false;
        }
        return countMin == 0;
    }
};

