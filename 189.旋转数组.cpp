/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // BF暴力法
        // 1. 新建array 然后将答案重新放入 cp[(i+k) % len] = nums[i]
        // 2. 接着移动剩余的元素
        // 3. 把取出元素放入array[0]开始  空间复杂度O(N)
        // int len = nums.size();
        // vector<int> cp(len,0);
        // for (int i = 0; i < len; i++) {
        //     cp[(i + k) % len] = nums[i];
        // }

        // for (int j = 0; j < len; j++) {
        //     nums[j] = cp[j];
        // }
        // int previous,temp;
        // 法二: 旋转k次 每次旋转1个数字
        // 先把最后一个元素记录好
        // 记录第一个元素 并交换 然后将后面的元素进行交换
        // 超出时间限制
        // for (int i = 0; i < k; i++) {
        //     previous = nums[nums.size() - 1];
        //     for (int j = 0; j < nums.size(); j++) {
        //         temp = nums[j];// exchange element
        //         nums[j] = previous;
        //         previous = temp;
        //     }
        // }

        // 法三 反转:
        int len = nums.size();
        k %= len;
        reverse(&nums[0],&nums[len]);
        reverse(&nums[0],&nums[k]);
        reverse(&nums[k],&nums[len]);
    
    }
};
// @lc code=end

