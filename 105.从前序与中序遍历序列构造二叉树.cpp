/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end) {
        int len = pre_end - pre_start + 1;
        if (len == 0) return nullptr;
        if (len == 1) return new TreeNode(preorder[pre_start]);
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int index = 0;
        for (index; index <= in_end; index++) {
            if (preorder[pre_start] == inorder[index]) break;
        }
        int left_len = index - in_start;
        int right_len = len - left_len - 1;
        root->left = helper(preorder, inorder, pre_start + 1, pre_start + left_len, in_start, in_start + left_len -1);
        root->right = helper(preorder, inorder, pre_end - right_len + 1, pre_end, index + 1, in_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

