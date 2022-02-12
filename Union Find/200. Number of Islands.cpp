//
// Created by Cauchy on 2022/2/11.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, m;
    unordered_map<int, int> parent;
public:
    int numIslands(vector<vector<char>> &grid) {
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                parent[i * n + j] = i * n + j;
        }

        vector<pair<int, int>> dir;
        dir.emplace_back(make_pair(1, 0));
        dir.emplace_back(make_pair(-1, 0));
        dir.emplace_back(make_pair(0, 1));
        dir.emplace_back(make_pair(0, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')
                    continue;

                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k].first;
                    int y = j + dir[k].second;
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if (grid[x][y] == '0')
                        continue;
                    if (FindSet(x * n + y) != FindSet(i * n + j))
                        Union(x * n + y, i * n + j);
                }
            }
        }

        unordered_set<int> Set;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0')
                    continue;
                Set.insert(FindSet(i * n + j));
            };
        }

        return Set.size();
    }

    int FindSet(int x) {
        if (x == parent[x])
            return parent[x];
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int p, int q) {
        p = parent[p];
        q = parent[q];
        bool flag;
        if (p / n < q / n)
            flag = true;
        else if (p / n == q / n && p % n <= q % n)
            flag = true;
        else
            flag = false;
        if (flag)
            parent[q] = p;
        else
            parent[p] = q;
    }


};