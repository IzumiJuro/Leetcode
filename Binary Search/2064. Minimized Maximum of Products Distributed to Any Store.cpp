#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = INT_MAX / 2;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (checkOk(n, quantities, mid)) 
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    bool checkOk(int n, vector<int>& quantities, int limit) {
        int count = 0;
        for (auto x: quantities) {
            if (x % limit == 0)
                count += x / limit;
            else
                count += x / limit + 1;
        }
        return n >= count;      
    }
};
