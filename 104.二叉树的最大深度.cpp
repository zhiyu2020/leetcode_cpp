/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int getDepth(TreeNode* root, int &count) {
        // terminator
        if (!root) return count;
        //process current level + drill down
        int l =  getDepth(root->left, count) + 1;
        int r = getDepth(root->right, count) + 1;
        return max(l, r);
    }

    int maxDepth(TreeNode* root) {
        int maxD = 0;
        return getDepth(root, maxD);
    }

};
// @lc code=end

