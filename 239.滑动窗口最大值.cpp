/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //BF 两个指针一个个滑动来比较值
        int len = nums.size();
        vector<int> maxval(len - k + 1);
        int Max_i = 0;
        for (int i = 0; i <= len - k; i++) {// 2 - 1
            Max_i = nums[i]; // 在这边先搞定初始化max才可以 避免走坑
            for (int j = i; j < i + k; j++) {// j = 1, j < 2 error
                // max = nums[j]; // 关键这个点报错了！！！循环有错误
                // if (nums[j+1] > max)
                //     max = nums[j+1];
                Max_i = max(Max_i,nums[j]);
            }
            maxval[i] = Max_i;
        }
        return maxval;
        // [1,-1] 1 报错了
    }
};
// @lc code=end
/*
class MonotonicQueue {
private:
    deque<int> data;
public:
    void push(int n) {
        while (!data.empty() && data.back() < n) 
            data.pop_back();
        data.push_back(n);
    }
    
    int max() { return data.front(); }
    
    void pop(int n) {
        if (!data.empty() && data.front() == n)
            data.pop_front();
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue window;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        if (i < k - 1) { //先填满窗口的前 k - 1
            window.push(nums[i]);
        } else { // 窗口向前滑动
            window.push(nums[i]);
            res.push_back(window.max());
            window.pop(nums[i - k + 1]);
        }
*/
