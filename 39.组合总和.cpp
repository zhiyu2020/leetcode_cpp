/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        backtrace(candidates, target, temp, 0);
        return res;
    }

    void backtrace(vector<int>& candidates, int remain, vector<int> temp, int level) {
        if (remain < 0) return;
        else if (remain == 0) res.push_back(temp);
        else {
            for (int i = level; i < candidates.size() && remain - candidates[i] >= 0; i++) {
                temp.push_back(candidates[i]);
                backtrace(candidates, remain - candidates[i], temp, i);
                temp.pop_back();
            }
        }
    }
};
// @lc code=end

