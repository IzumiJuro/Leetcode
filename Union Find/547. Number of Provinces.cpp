//
// Created by Cauchy on 2022/2/11.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> parent;
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < n; i++)
            parent.emplace_back(i);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 0)
                    continue;
                if (Find(i) != Find(j))
                    Union(i, j);
            }
        }

        unordered_set<int> Set;
        for (int i = 0; i < n; i++) {
            parent[i] = Find(i);
            Set.emplace(parent[i]);
        }

        return Set.size();
//        int count = 0;
//        for (int i = 0; i < n; i++)
//            if (parent[i] == i)
//                count++;
//        return count;
    }

    int Find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = Find(parent[x]);
    }

    void Union(int p, int q) {
        p = parent[p];
        q = parent[q];
        if (p <= q)
            parent[p] = q;
        else
            parent[q] = p;
    }
};