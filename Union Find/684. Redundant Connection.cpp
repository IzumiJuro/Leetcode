//
// Created by Cauchy on 2022/2/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> parent;
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        int n = edges.size();

        for (int i = 0; i < n; i++) {
            parent[edges[i][0]] = edges[i][0];
            parent[edges[i][1]] = edges[i][1];
        }

        for (int i = 0; i < n; i++) {
            if (FindSet(edges[i][0]) == FindSet(edges[i][1]))
                return edges[i];
            else
                Union(edges[i][0], edges[i][1]);
        }
        return edges[0];
    }

    int FindSet(int x) {
        if (x == parent[x])
            return parent[x];
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int x, int y) {
        x = parent[x];
        y = parent[y];
        if (x <= y)
            parent[y] = x;
        else
            parent[x] = y;
    }
};