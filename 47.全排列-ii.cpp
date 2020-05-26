/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<int> nums, vector<vector<int>>& res, int level) {
        if (nums.size() - 1 == level) res.push_back(nums);
        for (int i = level; i < nums.size(); i++) {
            if (level == i || (nums[i] != nums[level])) {
                swap(nums[i], nums[level]);
                dfs(nums, res, level + 1);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(nums, res, 0);
        return res;
    }
};
// @lc code=end

