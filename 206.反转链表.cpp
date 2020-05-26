/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // solution1: 迭代法
        // 1.创建pre = NULL cur
        // 2.循环cur
        // 3.在cur循环中 cur指向pre 并且 cur pre需要更新 
        // time O(N) Space O(1)
        // ListNode* pre = NULL;
        // ListNode* cur = head;
        // ListNode* tmp = NULL;

        // while (cur) {
        //     //keep cur next node
        //     tmp = cur->next;
        //     // cur 指向 pre
        //     cur->next = pre;
        //     //update cur & pre

        //     pre = cur;
        //     cur = tmp;
        // }

        // return pre;

        //solution2 recursion 递归
        // time O(N) Space O(N)
        // 1->2->3->4->5
        // 1.写终止条件 head/ head->next = NULL 返回 ；递归调用函数先到5
        // 2.动态图: head:4 将head->next(5)指向head自己 并且断掉head->next防止出现循环
        if(head == NULL || head->next == NULL)
                return head;
        ListNode* cur = reverseList(head->next);

        head->next->next = head;
        head->next = NULL;
        return cur;
    }


};
// @lc code=end

