/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // BF algorithms time limit 可行
        // int area = 0;
        // for (int i = 0; i < height.size() - 1; i++) {
        //     for (int j = i + 1; j < height.size(); j++) {
        //         area = max(area,min(height[i],height[j]) * (j - i));
        //     }
        // }
        // return area;

        // 双指针法:
        int l = 0, r = height.size() - 1;
        int maxarea = 0; // 更新最大area
        int h = 0;
        while (l < r) {
            maxarea = max(maxarea,(r-l) * min(height[l], height[r]));
            h = min(height[l], height[r]);
            // 此处还可以优化 
            // if (height[l] < height[r]) 
            //     l++;
            // else
            //     r--;

            // optimize result!
            while(height[l] <= h && l < r) l++;
            while(height[r] <= h && l < r) r--;
        }
        return maxarea;
    }
};
// @lc code=end

