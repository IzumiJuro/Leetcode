//
// Created by Cauchy on 2022/2/12.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<int, int> parent;
    int n, m;
public:
    void solve(vector<vector<char>> &board) {
        n = board.size();
        m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X')
                    continue;
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                    parent[i * m + j] = -1;
                else
                    parent[i * m + j] = i * m + j;
            }
        }

        vector<pair<int, int>> dir;
        dir.emplace_back(make_pair(1, 0));
        dir.emplace_back(make_pair(-1, 0));
        dir.emplace_back(make_pair(0, 1));
        dir.emplace_back(make_pair(0, -1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X')
                    continue;
                for (int k = 0; k < 4; k++) {
                    int x = i + dir[k].first;
                    int y = j + dir[k].second;
                    if (x < 0 || x >= n || y < 0 || y >= m)
                        continue;
                    if (board[x][y] == 'X')
                        continue;
                    if (FindSet(x * m + y) != FindSet(i * m + j))
                        Union(x * m + y, i * m + j);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X')
                    continue;
                if (FindSet(i * m + j) != -1)
                    board[i][j] = 'X';
            }
        }
    }

    int FindSet(int x) {
        if (parent[x] == -1)
            return -1;
        if (x == parent[x])
            return parent[x];
        return parent[x] = FindSet(parent[x]);
    }

    void Union(int p, int q) {
        p = parent[p];
        q = parent[q];
        bool flag;
        if (p / m < q / m)
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