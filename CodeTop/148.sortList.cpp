/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        quickSort(head, nullptr);
        return head;
    }
    void quickSort(ListNode* head, ListNode* tail){
        if(head == tail || head->next == tail){
            return;
        }
        int pivot = head->val;
        ListNode* left = head;
        ListNode* cur = head->next;
        while (cur != nullptr && cur != tail)
        {
            if(cur->val < pivot){
                left = left->next;
                swap(left->val, cur->val);
            }
            cur = cur->next;
        }
        swap(left->val, head->val);

        quickSort(head,left);
        quickSort(left->next,tail);
    }
};
// @lc code=end