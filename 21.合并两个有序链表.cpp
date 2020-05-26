/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // iteration 迭代法
        // 1.新建一个链表prehead &temp用于挂载比较两端的val 
        // 2.比较两个升序链表后 谁小就放入进去
        // 3.由于两个链表都有null结尾 选择一个null即可
        // 4.返回prehead
        // ListNode* prehead = new ListNode(-1);
        // ListNode* temp = prehead;

        // while (l1 && l2) {
        //     if (l1->val < l2->val) {
        //         temp->next = l1;
        //         temp = temp->next;
        //         l1 = l1->next;
        //     } else {
        //         temp->next = l2;
        //         temp = temp->next;
        //         l2 = l2->next;
        //     }
        // }

        // // connect one of non-null to temp linkedlist
        // if (l1 == NULL) temp->next = l2;
        // else temp->next = l1;
        

        // return prehead->next;

        // 递归法  根据公式得到:
        //  l1[0] < l2[0] : l1[0],merge(l1[1],l2[0])
        //  l1[0] >=l2[0] : l1[0],merge(l1[0],l2[1])
        if (l1 == NULL) return l2;
        else if (l2 == NULL) return l1;
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next,l2); // error 我没有写l1->next = xxx 直接call func 导致报错
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }

    }
};
// @lc code=end

