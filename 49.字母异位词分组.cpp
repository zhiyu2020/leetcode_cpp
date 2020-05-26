/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // sort + hashmap
        // 1.首先创建hashmap 排序每个str 按序排列的作为key value
        // 2.以key为头 放入strs 遍历完成
        // 3.创建返回类型 & idx 将结果放入答案中
        unordered_map<string, vector<string>> hashmap;
        for (auto str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hashmap[temp].push_back(str);
        }
        int index = 0;
        int len = hashmap.size();
        vector<vector<string>> res(len);
        for (auto x : hashmap) {
            res[index++] = x.second;
        }
        return res;
    }
};
// @lc code=end

