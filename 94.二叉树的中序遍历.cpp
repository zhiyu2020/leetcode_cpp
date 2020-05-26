/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> res; // 为什么会在这边 在递归调用的时候 防止创建不同的res 
    vector<int> inorderTraversal(TreeNode* root) {
        //vector<int> res;
        if (root== NULL) return res;
        if (root->left)  inorderTraversal(root->left);
        res.push_back(root->val);
        if (root->right) inorderTraversal(root->right);

        return res; 
    }
};
// @lc code=end

