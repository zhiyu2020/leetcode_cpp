/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // // 1 双指针法 30%
        // // 先定义快慢指针 快指针cur 慢指针从0开始放非0元素
        // int slowP = 0, cur = 0;
        // // 遍历循环 当cur发现非0元素 将其放到慢指针指向位置
        // for (cur; cur < nums.size(); cur++) {
        //     if (nums[cur] != 0) {
        //         // update elements
        //         nums[slowP] = nums[cur];
        //         ++slowP;
        //     }
        // }
        // // 在后面的位置+0
        // while (slowP < nums.size()) {
        //     nums[slowP] = 0;
        //     slowP++;
        // }
        // optimization
        // 快慢指针后
        // 在循环处优化 合并成一个方式使用swap

        // 50%
        // for (int slowP = 0, cur = 0; cur < nums.size(); cur++) {
        //     if (nums[cur] != 0) swap(nums[slowP++], nums[cur]);
        // }

        int slowP = 0, cur = 0;
        for (cur; cur < nums.size(); cur++) {
            if (nums[cur] != 0) {
                nums[slowP++] = nums[cur];
            }
        }

        while (slowP < nums.size()) {
            nums[slowP++] = 0;
        }

    }
};

// @lc code=end

/* python
# in-place
def moveZeroes(self, nums):
    zero = 0  # records the position of "0"
    for i in xrange(len(nums)):
        if nums[i] != 0:
            nums[i], nums[zero] = nums[zero], nums[i]
            zero += 1
*/