//
// Created by Cauchy on 2022/2/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, string> Father;
    unordered_map<string, string> Owner;
    unordered_map<string, set<string>> Group;
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int m = accounts.size();

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                Father[accounts[i][j]] = accounts[i][j];
                Owner[accounts[i][j]] = accounts[i][0];
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 2; j < accounts[i].size(); j++) {
                if (FindSet(accounts[i][j]) != FindSet(accounts[i][j - 1]))
                    Union(accounts[i][j], accounts[i][j - 1]);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string parent = FindSet(accounts[i][j]);
                Group[parent].emplace(accounts[i][j]);
            }
        }

        vector<vector<string>> res;
        for (auto a: Group) {
            vector<string> temp;
            temp.emplace_back(Owner[a.first]);
            for (auto b: a.second)
                temp.emplace_back(b);
            res.emplace_back(temp);
        }
        return res;
    }

    string FindSet(string x) {
        if (x == Father[x])
            return Father[x];
        return Father[x] = FindSet(Father[x]);
    }

    void Union(string x, string y) {
        x = Father[x];
        y = Father[y];
        if (x < y)
            Father[y] = x;
        else
            Father[x] = y;
    }
};