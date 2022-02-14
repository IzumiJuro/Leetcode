//
// Created by Cauchy on 2022/2/14.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int Father[20000];
    int states[20000];

    int FindFather(int x) {
        if (x != Father[x])
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x < y)
            Father[y] = x;
        else
            Father[x] = y;
    }

public:
    vector<int> groupStrings(vector<string> &words) {
        int n = words.size();


        for (int i = 0; i < n; i++) {
            Father[i] = i;
        }
        unordered_map<int, int> Map;
        for (int i = 0; i < n; i++) {
            string &word = words[i];
            int state = 0;
            for (int j = 0; j < word.size(); j++) {
                int ch = word[j] - 'a';
                state |= (1 << ch);
            }
            states[i] = state;
            if (Map.find(state) == Map.end())
                Map[state] = i;
            else {
                int k = Map[state];
                if (FindFather(i) != FindFather(k))
                    Union(i, k);
            }
        }

        for (int i = 0; i < n; i++) {
            int A = states[i];
            for (int j = 0; j < 26; j++) {
                if (((A >> j) & 1) == 0)
                    continue;
                int B = states[i] - (1 << j);
                if (Map.find(B) == Map.end())
                    Map[B] = i;
                else {
                    int k = Map[B];
                    if (FindFather(i) != FindFather(k))
                        Union(i, k);
                }
            }
        }

        unordered_map<int, int> group;
        for (int i = 0; i < n; i++)
            group[FindFather(i)]++;

        int maxGroupSize = 0;
        for (auto x: group)
            maxGroupSize = max(maxGroupSize, x.second);

        return {(int) group.size(), maxGroupSize};
    }
};