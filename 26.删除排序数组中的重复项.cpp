/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // 双指针法:
        // 1.设置fast slow两个指针 fast(1) = slow(0) + 1
        // 2.nums[fast] == nums[slow] => fast++ 
        // 3.           !=            => fast++ slow++ nums[slow] <= nums[fast]
        // 4.需要返回count
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return 1;
        int fast = 1, slow = 0;
        for (fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
};
// @lc code=end

