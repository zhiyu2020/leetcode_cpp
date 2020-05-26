/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {

// 1.BF
// 2.HASH MAP
// 3.双指针算法 坑 避免重复 排序 双指针左右边界
public:
    // 双指针算法
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 1. 进行排序 创建res 循环1:遍历第一个sum元素
        vector<vector<int>> res;
        int len = nums.size();
        std::sort(nums.begin(),nums.end());
        for (int i = 0; i < len; i++) {
        // 2. 定义左端target 以及两个数 i j 求ij和与target比较 并相对更新ij位置
            int target = -nums[i];
            int left = i + 1;// 没有分析清楚 i+1 和 nums[i+1]的区别 left right指的是position
            int right = len - 1;
            //int sum = nums[left] + nums[right];// 不能把sum放在上层 固定死了sum 需要实时更新
        // 3.如果匹配了 需要新建一个vector把对应ij target放入进去 并放入res 同时还要注意ij继续下去需要跳过相同的值 
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    vector<int> temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    res.push_back(temp);
                    //jmp same val for left
                    while (left < right && nums[left] == temp[1]) // 没有考虑要更新当前left 到下一个点 right同理 nums[left] == nums[left+1]
                        left++; // 这边省略left++ 合并在一起了
                    while (left < right && nums[right] == temp[2])
                        right--;
                }
            } // 坑 注意 3个值都要避免重复
            while (i < len - 1 && nums[i] == nums[i + 1] ) i++;
        }
        return res;
    }
};
// @lc code=end

