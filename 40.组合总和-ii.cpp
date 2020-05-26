/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, temp, 0);
        return res;
    }

    void backtrace(vector<int>& candidates, int remain, vector<int> temp, int level) {
        if (remain == 0) res.push_back(temp);
        else {
            for (int i = level; i < candidates.size() && remain - candidates[i] >= 0; i++) {
                if (i > level && candidates[i] == candidates[i - 1]) continue;
                temp.push_back(candidates[i]);
                backtrace(candidates, remain - candidates[i], temp, i + 1);
                temp.pop_back();
            }
        }
    }
};
// @lc code=end

