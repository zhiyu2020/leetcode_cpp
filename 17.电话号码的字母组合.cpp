/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return res;
        string temp;
        vector<vector<char>> table(2, vector<char>());
        table.push_back(vector<char>{'a','b','c'}); // index 2
        table.push_back(vector<char>{'d','e','f'}); // 3
        table.push_back(vector<char>{'g','h','i'});
        table.push_back(vector<char>{'j','k','l'}); // 5
        table.push_back(vector<char>{'m','n','o'});
        table.push_back(vector<char>{'p','q','r','s'}); // 7
        table.push_back(vector<char>{'t','u','v'});
        table.push_back(vector<char>{'w','x','y','z'}); // 9

        backtrace(table, digits, temp, 0);
        return res;
    }

    void backtrace(const vector<vector<char>> table, const string digits, string& temp, int level) {
        if (digits.size() == level) res.push_back(temp);
        else {
            for (int i = 0; i < table[digits[level] - '0'].size(); i++) {
                temp.push_back(table[digits[level] - '0'][i]);
                backtrace(table, digits, temp, level + 1);
                temp.pop_back();
            }
        }
    }
};
// @lc code=end

