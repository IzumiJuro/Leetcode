//
// Created by Cauchy on 2022/2/4.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> recoverArray(int n, vector<int> &sums) {
        vector<int> res;
        if (dfs(sums, n, res))
            return res;
        return {};
    }

    static vector<int> split1(vector<int> &sums, int x) {
        int k = sums.size();
        vector<int> visited(k);
        vector<int> res;
        int i = k - 1, j = k - 1;
        for (int t = 0; t < k / 2; t++) {
            while (i >= 0 && visited[i])
                i--;
            if (i < 0) return {};
            visited[i] = 1;

            while (j >= 0 && (visited[j] || sums[j] != sums[i] - x))
                j--;
            if (j < 0) return {};
            visited[j] = 1;

            res.emplace_back(sums[j]);
        }
        return res;
    }

    static vector<int> split2(vector<int> &sums, int x) {
        int k = sums.size();
        vector<int> visited(k);
        vector<int> res;
        int i = 0, j = 0;
        for (int t = 0; t < k / 2; t++) {
            while (i < k && visited[i])
                i++;
            if (i >= k) return {};
            visited[i] = 1;

            while (j < k && (visited[j] || sums[j] != sums[i] - x))
                j++;
            if (j >= k) return {};
            visited[j] = 1;

            res.emplace_back(sums[j]);
        }
        return res;
    }

    bool dfs(vector<int> sums, int n, vector<int> &res) {
        if (n == 1) {
            if (sums[0] != 0 && sums[1] != 0)
                return false;
            else {
                res.emplace_back(sums[0] == 0 ? sums[1] : sums[0]);
                return true;
            }
        }
        int k = sums.size();
        sort(sums.begin(), sums.end());

        // suppose x is the minimum positive number
        int x = sums[k - 1] - sums[k - 2];
        vector<int> sums1 = split1(sums, x);
        if (sums1.size() == k / 2) {
            res.emplace_back(x);
            if (dfs(sums1, n - 1, res))
                return true;
            res.pop_back();
        }

        // suppose x is the maximum negative number
        x = -(sums[k - 1] - sums[k - 2]);
        vector<int> sums2 = split2(sums, x);
        if (sums2.size() == k / 2) {
            res.emplace_back(x);
            if (dfs(sums2, n - 1, res))
                return true;
            res.pop_back();
        }

        return false;
    }
};