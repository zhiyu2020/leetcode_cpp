/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // 按列来求
        int len = height.size(), sum = 0;
        for (int i = 1; i < len - 1; i++) {
            int left_max = height[i];
            for (int j = i - 1; j >= 0; j--) {
                left_max = max(height[j], left_max);
            }
            int right_max = height[i];
            for (int j = i + 1; j <= len - 1; j++) {
                right_max = max(height[j], right_max);
            }

            int min_height = min(right_max, left_max);
            if (min_height > height[i]) {
                sum += (min_height - height[i]);
            }
        }
        return sum;

        // DP :可以将上述向左向右遍历 做进一步简化
        // left_max[i] = max(left_max[i-1],height[i-1]) 向左比较得到max
        // right_max[i] = max(right_max[i+1],height[i+1]) 向右比较得到max
    //     int len = height.size();
    //     int sum = 0;
    //     vector<int> left_max(len, 0);
    //     vector<int> right_max(len, 0);
    //     for (int i = 1; i < len - 1; i++) {
    //         left_max[i] = max(left_max[i - 1], height[i - 1]);
    //     }
    //     for (int i = len - 2; i >= 1; i--) {
    //         right_max[i] = max(right_max[i + 1], height[i + 1]);
    //     }
    //     for (int i = 1; i < len - 1; i++) {
    //         int min_v = min(left_max[i], right_max[i]);
    //         if (min_v > height[i]) {
    //             sum += min_v - height[i];
    //         }
    //     }
    //     return sum;
    }
};
// @lc code=end

