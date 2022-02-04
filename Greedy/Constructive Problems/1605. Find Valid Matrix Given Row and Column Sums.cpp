//
// Created by Cauchy on 2022/2/5.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int> &rowSum, vector<int> &colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        auto res = vector<vector<int>>(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = min(rowSum[i], colSum[j]);
                res[i][j] = x;
                rowSum[i] -= x;
                colSum[j] -= x;
            }
        }
        return res;
    }
};