/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> res;
        TreeNode* rt = root;
        q.push(rt);
        int level = 0;
        while (q.size()) {
            int size = q.size();
            vector<int> curLevel;
            for (int i = 0; i < size; i++) {
                rt = q.front(); q.pop();
                if ((level & 1) == 0) {
                    curLevel[i] = rt->val; // odd level
                } else {
                    curLevel[size - i - 1] = rt->val;// even
                }
                if (rt->left) q.push(rt->left);
                if (rt->right) q.push(rt->right);
            }
            level++;
            res.push_back(curLevel);
        }
        return res;
    }
};
// @lc code=end

