//
// Created by Cauchy on 2022/2/8.
//
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<TreeNode *, int> memo;

    int rob(TreeNode *root) {
        if (root == nullptr) return 0;
        if (memo[root]) return memo[root];

        int val = 0;

        if (root->left)
            val += rob(root->left->left) + rob(root->left->right);
        if (root->right)
            val += rob(root->right->left) + rob(root->right->right);

        memo[root] = max(root->val + val, rob(root->left) + rob(root->right));
        return memo[root];
    }
};