/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;// root == NULL 没有node
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (root->left && root->right ) return min(l, r) + 1; // 左右都是有存在高度的
        else return l + r + 1; // 其中必然有一个root = null
    }
};
// @lc code=end

