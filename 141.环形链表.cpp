/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
    bool hasCycle(ListNode *head) {
        // BF 遍历链表 将val记录到创建的vector中 并将当前val与vector中进行比较 如果相同
        // 表示有环 否则没有环
    //     vector<int> record{0};
    //     while (head) {
    //         for (int i = 0; i < record.size(); i++) {
    //             if (record[i] = head->val) 
    //                 return true;
    //         }
    //         record.push_back(head->val);
    //         head = head->next;
    //     }
    //     return false;
    // }

    // // 1 hash solution
    // map<ListNode*,int> hashtab;
    // ListNode* it = head;
    // while (it) {
    //     if (hashtab[it] == 1) {
    //         return true;
    //     }
    //     hashtab[it]++;
    //     it = it->next;
    // }
    // return false;
    // }

    // solution 2. fast slow point
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) return true;
    }
    return false;
    }
};
// @lc code=end

