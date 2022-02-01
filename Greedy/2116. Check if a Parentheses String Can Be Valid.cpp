//
// Created by Cauchy on 2022/2/1.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.size() & 1) return false;
        int countMax = 0;
        int countMin = 0;
        for (int i = 0; i < s.size(); i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    countMax++;
                    countMin++;
                } else {
                    countMax--;
                    countMin--;
                }
            } else {
                countMax++;
                countMin--;
            }
            if (countMax < 0)
                return false;
            if (countMin < 0) // 与678不同在于，678题星号可以当作空字符而这题不行，所以最小的左括号数要加2，因为多了一个左括号，少了一个右括号。
                countMin += 2;
        }
        return countMin == 0;
    }
};
