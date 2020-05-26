/*
 * @lc app=leetcode.cn id=641 lang=cpp
 *
 * [641] 设计循环双端队列
 */

// @lc code=start
#include<iostream>
#include<vector>

using namespace std;

class MyCircularDeque {
    //一般来说 前移动 需要 + kapacity % kapacity
    // 后移动 -+1 % kapacity即可
private:
    int front;
    int rear;
    int count;
    int kapacity;
    // forget buffer
    vector<int> buffer;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque (int k): buffer(k,0), front(k - 1), rear(0), count(0), kapacity(k) {

    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (count == kapacity) {
            return false;
        }
        buffer[front] = value;
        front = (front - 1 + kapacity) % kapacity;
        ++count;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (count == kapacity) {
            return false;
        }
        buffer[rear] = value;
        rear = (rear + 1) % kapacity;
        ++count;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (count == 0)
            return false;
        front = (front + 1) % kapacity;
        --count;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (count == 0) 
            return false;
        rear = (rear - 1 + kapacity) % kapacity;
        --count;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (count == 0)
            return -1;
        return buffer[(front + 1)% kapacity];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
         if (count == 0)
            return -1;
        return buffer[(rear - 1 + kapacity)% kapacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return count == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return count == kapacity;// front == rear error
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

