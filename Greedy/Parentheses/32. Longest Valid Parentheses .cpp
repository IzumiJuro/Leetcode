//
// Created by Cauchy on 2022/2/1.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                st.push(i);
            else {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    res = max(res, i - st.top());
            }
        }
        return res;
    }
};