//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;

class Leetcode {
    vector<int> Father;
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
        int n = pairs.size();
        for (int i = 0; i < n; i++) {
            Father[i] = i;
        }

        for (auto &x: pairs) {
            int a = x[0];
            int b = x[1];
            if (FindSet(a) != FindSet(b))
                Union(a, b);
        }

        unordered_map<int, vector<int>> Map;
        for (int i = 0; i < n; i++) {
            Map[Father[i]].emplace_back(i);
        }

        for (auto x: Map) {
            string temp;
            for (auto index: x.second)
                temp.push_back(s[index]);
            sort(temp.begin(), temp.end());
            int k = 0;
            for (auto index: x.second) {
                s[index] = temp[k];
                k++;
            }
        }

        return s;

    }

    int FindSet(int x) {
        if (x == Father[x])
            return Father[x];
        return Father[x] = FindSet(Father[x]);
    }

    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if (x <= y)
            y = Father[x];
        else
            x = Father[y];
    }

};

int main() {
    Leetcode solution;
    vector<vector<int>> requests = {{0, 3},
                                    {1, 2},
                                    {0, 2},
    };
    solution.smallestStringWithSwaps("dcab", requests);
}