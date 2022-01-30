//
// Created by Cauchy on 2022/1/28.
//
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words)
    {
        unordered_map<string, int> count1;
        unordered_map<string, int> count2;
        unordered_map<string, int> count3;

        for (auto& str: words)
        {
            string str2 = str;
            reverse(str2.begin(), str2.end());
            if(str == str2)
                count3[str]++;
            else
            {
                string key = min(str, str2);
                if (key == str)
                    count1[key]++;
                else
                    count2[key]++;
            }
        }

        int res = 0;
        for (auto& [key, val]: count1)
        {
            int a = count1[key];
            int b = count2[key];
            int k = min(a, b);
            res += k*2*2;
        }

        int flag = 0;
        for (auto& [key, val]: count3)
        {
            int k = val/2;
            res += k*2*2;
            if(val%2==1)
                flag = 1;
        }

        return res+flag*2;
    }
};