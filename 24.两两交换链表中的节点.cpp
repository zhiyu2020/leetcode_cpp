/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        // recursion
        //end condition
        // 前->head->next->后
        // 1 前->next & head -> 后
        // 2 next -> head
        // if (head == NULL || head->next == NULL)
        //     return head;
        // ListNode* next = head->next;//denote next
        // head->next = swapPairs(next->next);// finish step 1
        // next->next = head; // finish step 2
        // return next; // error I write return head already changed for head

        // 2 iterate
        // 1. 新建两个节点 cur(和p 绑定) & p(空头node -> head) [](cur)  -> (head)firstNode -> secondNode -> ...   
        // 2. 循环 条件是 head head->next 不为空
        //     建立2个Node 这两个node (firstNode secondeNode)
        //     2.1 cur 指向 secondNode ([](cur) -> secondNode)
        //     2.2 firstNode 指向 secondeNode后一个node (firstNode -> ...)
        //     2.3 secondeNode 指向 firstNode  (secondNode -> firstNode)
        //     更新 cur 以及head 
        // 3.  返回p->next即可
        ListNode* p = new ListNode(0);
        p->next = head;
        ListNode* cur = p;

        while (head != NULL && head->next != NULL) {
            ListNode* firstNode = cur->next;
            ListNode* secondNode = cur->next->next;

            cur->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            cur = firstNode;
            head = firstNode->next;
        }

        return p->next;
    }
};
// @lc code=end

