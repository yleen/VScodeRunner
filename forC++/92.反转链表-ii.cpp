/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if(left==1){//
           return revertList(head,right);
        }
        head->next = reverseBetween(head->next,left-1,right-1);
        return head;
    }
    ListNode *currListNode=nullptr;
    ListNode *revertList(ListNode *head,int index){
        if(index==1){//
            currListNode=head->next;//
            return head;//
        }
        ListNode *listNode=revertList(head->next,index-1);
        head->next->next=head;
        head->next=currListNode;
        return listNode;//
    }
};
// @lc code=end
