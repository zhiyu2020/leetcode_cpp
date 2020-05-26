/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        source.push(x);
        if (helper.empty() || helper.top() > x) helper.push(x);
        else helper.push(helper.top());
    }
    
    // void pop() {
    //         helper.pop();
    //         source.pop();
    // }
    
    // Optimize 非同步 等x < min才可以放入 
    void push(int x) {
        source.push(x);
        if (helper.empty() || getMin() >= x) helper.push(x);
    }
    // 出栈时 最小值才同步 入栈时 最小值才同步
    void pop() {
        if (getMin == source.top()) helper.pop();
        source.pop();
    }
    int top() {
        return source.top();
    }
    
    int getMin() {
        return helper.top();
    }
private:
    stack<int> source;
    stack<int> helper;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

// @lc code=end

