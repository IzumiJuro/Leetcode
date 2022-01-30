//
// Created by Cauchy on 2022/1/29.
//

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(string s) {
        int count = 0, unmatch = 0;
        for (auto ch: s) {
            if (ch == '[')
                count++;
            else
                count--;
            if (count < 0) {
                unmatch++;
                count = 0;
            }
        }
        return (unmatch + 1) >> 1;
    }
};