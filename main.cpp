//
// Created by Cauchy on 2022/1/30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> buildings;
public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        int m = requests.size();
        buildings.resize(n);

        for (int k = m; k >= 1; k--) {
            int cur = (1 << k) - 1;
            int limit = (1 << m);
            while (cur < limit) {
                /**
                 *  do something
                 */
                if (check(cur, n, requests))
                    return k;
                int lb = cur & -cur;
                int r = cur + lb;
                cur = ((r ^ cur) >> (__builtin_ctz(lb) + 2)) | r;
                // 或者 cur = ((r ^ cur) >> 2 / lb) | r;
            }
        }
        return 0;
    }

    bool check(int s, int n, vector<vector<int>> &requests) {
        int m = requests.size();
        fill(buildings.begin(), buildings.end(), 0);
        for (int i = 0; i < m; i++) {
            if (((s >> i) & 1) == 1) {
                buildings[requests[i][0]]++;
                buildings[requests[i][1]]--;
            }
        }
        int flag = 1;
        for (int i = 0; i < n; i++) {
            if (buildings[i] != 0) {
                flag = 0;
                break;
            }
        }
        return flag;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> requests = {{0, 1},
                                    {1, 0},
                                    {0, 1},
                                    {1, 2},
                                    {2, 0},
                                    {3, 4}};
    solution.maximumRequests(5, requests);
}