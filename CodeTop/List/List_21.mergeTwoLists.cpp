/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * [easy]
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

//迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* retList=new ListNode(-1);//这里注意 是把返回值设置-1
        ListNode* head=retList;
        while (l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<l2->val){
                head->next=l1;
                l1=l1->next;
            }else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1!=nullptr) head->next=l1; //注意这里使用if即可 若使用while纯属画蛇添足
        if(l2!=nullptr) head->next=l2;
        return retList->next;
    }
};

//TODO 递归
// @lc code=end