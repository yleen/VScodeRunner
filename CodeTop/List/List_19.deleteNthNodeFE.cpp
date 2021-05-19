/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hair=new ListNode(0);
        hair->next=head;
        ListNode* fast=head;
        ListNode* slow=hair;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while (fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* next=slow->next;
        slow->next=slow->next->next;
        next->next=nullptr;
        return hair->next;
    }
};
// @lc code=end

