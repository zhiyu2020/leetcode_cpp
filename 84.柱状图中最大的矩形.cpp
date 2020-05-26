/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    // 分治法
    // int CalculateMaxArea(vector<int>& heights, int start, int end) {
        
    // }
    int largestRectangleArea(vector<int>& heights) {
       // 暴力法
       // 1.遍历循环一遍i 从0到len-1
       // 2.向左边看 找比i高度大的下标
       // 3.向右看齐 找i高度大下标 计算得到maxarea 超时了
    //    int left_idx, right_idx;
    //    int maxarea = 0;
    //    for (int i = 0; i < heights.size(); i++) {
    //        left_idx = i, right_idx = i;
    //        while (left_idx >= 0 && heights[i] <= heights[left_idx]) left_idx--;
    //        while (right_idx <= heights.size() - 1 && heights[i] <= heights[right_idx]) right_idx++; // 记住边界的条件 我写错了 需要补上 =
    //        maxarea = max(maxarea,(right_idx - left_idx - 1)*heights[i]);
    //    }
    //    return maxarea;


    // 2.维护一个stack
    // 首先创建一个stack 记得首位是-1
    // 进行遍历 当i的元素 < stack.top 计算area 
    //      首先得到高度(top) pop掉 然后记录左边界 是stack前面一个元素 得到后计算area
    //      否则是正常push加入元素
        heights.push_back(0);// [1] 报错了
        int n = heights.size(), area = 0;
        stack<int> indexes;
        for (int i = 0; i < n; i++) {
            while (!indexes.empty() && heights[indexes.top()] > heights[i]) {
                int h = heights[indexes.top()]; indexes.pop();
                int l = indexes.empty() ? -1 : indexes.top();
                area = max(area, h * (i - l - 1));// 左右边界offset相差1
            }
            indexes.push(i);
        }
        return area; 

    }

};
// @lc code=end

