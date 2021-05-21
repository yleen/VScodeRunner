/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sumList=new ListNode(0);
        ListNode* head=sumList;
        int add =0,sum=0;
        while(l1!=nullptr||l2!=nullptr||add!=0){
            if(l1!=nullptr){
                add+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                add+=l2->val;
                l2=l2->next;
            }
            sumList->next=new ListNode(add%10);
            sumList=sumList->next;
            add =add/10;
        }
        return head->next;
    }
};
// @lc code=end

