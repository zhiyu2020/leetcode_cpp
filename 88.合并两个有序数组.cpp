/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // BF 将nums2放入nums1后 再排序即可
        // for (int i = 0; i < n; i++) {
        //     nums1[i + m] = nums2[i];
        // }
        // sort(nums1.begin(),nums1.end());

        // 2双指针法 从后 
        // 1.创建三个flag  a b i从后往前比较
        // 2.循环比较nums1 和 nums2 谁大把val放进去
        // 3.若b>0 把剩余val cp进去即可  空间 O(1)
        // int a = m -1, b = n - 1, i = m + n - 1;
        // while (a >= 0 && b >=0) {
        //     if (nums1[a] > nums2[b]) nums1[i--] = nums1[a--];
        //     else nums1[i--] = nums2[b--]; 
        // }

        // while (b >= 0) nums1[i--] = nums2[b--];
        int first = m - 1, second = n - 1, i = m + n - 1;
        while (first >= 0 && second >= 0) {
            if (nums1[first] > nums2[second]) nums1[i--] = nums1[first--];
            else nums1[i--] = nums2[second--];
        }
        while (second >= 0) nums1[i--] = nums2[second--];
    }
};
// @lc code=end

