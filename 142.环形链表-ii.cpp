/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        // 关键是推导公式
        // 快慢指针法:
        // 1. 构建环 判断是否有环 快慢指针相遇 跳出循环
        // 2. 将快指针设为head step 为1 慢指针继续运动 step 1 相遇 返回快指针
        // ListNode* fast = head;
        // ListNode* slow = head;

        // while (1) {
        //     if (fast == NULL || fast->next == NULL) return NULL;
        //     fast = fast->next->next;
        //     slow = slow->next;
        //     if (fast == slow) break; 
        // }

        // fast = head;
        // while (1) {
        //     if (fast == slow) return fast;
        //     fast = fast->next;
        //     slow = slow->next;
        // }

        // solution 2. hash tab
        map<ListNode*,int> hashtab;
        ListNode* it = head;
        while (it) {
            if (hashtab[it] == 1) {
                return it;
            }
            hashtab[it]++;
            it = it->next;
        }
        return NULL;

    }
};
// @lc code=end

