//
// Created by Cauchy on 2022/2/2.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
    int maxLen;
    vector<string> ans;
public:
    // removed: unmatched right parentheses
    // count: unmatched left parentheses
    vector<string> removeInvalidParentheses(string s) {
        int count = 0;
        int removed = 0;
        for (auto ch: s) {
            if (ch == '(')
                count++;
            else if (ch == ')')
                count--;
            if (count < 0) {
                removed++;
                count = 0;
            }
        }
        removed += count;
        maxLen = s.size() - removed; // the length of substring

        string curStr = "";
        dfs(s, 0, curStr, 0);
        return ans;
    }
    //Pruning conditions:
    // (1) count < 0
    // (2) curStr.size() > maxLen

    // count: unmatched left parentheses
    void dfs(string &s, int i, string curStr, int count) {
        if (count < 0) return;
        if (curStr.size() > maxLen) return;
        if (i == s.size()) {
            if (count == 0 && curStr.size() == maxLen)
                ans.emplace_back(curStr);
            return;
        }

        if (s[i] != '(' && s[i] != ')')
            dfs(s, i + 1, curStr + s.substr(i, 1), count);
        else {
            dfs(s, i + 1, curStr + s.substr(i, 1), count + (s[i] == '(' ? 1 : -1));
            if (curStr.empty() || s[i] != curStr.back())
                dfs(s, i + 1, curStr, count);
        }
    }
};
// Searching in an array
//1.  if s[i] != curStr.back()
//    curStr -> curStr+s[i]
//
//2.  if s[i] == curStr.back()
//    curStr -> curStr+s[i]