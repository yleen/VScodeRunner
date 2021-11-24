/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/
 * [medium]
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
    ListNode *successor =nullptr;
    // 反转以 head 为起点的 n 个节点，返回新的头结点
    ListNode *revertList(ListNode *head,int index){
        if(index==1){//
            // 记录第 n + 1 个节点
            successor =head->next;//
            return head;//
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode *listNode=revertList(head->next,index-1);
        head->next->next=head;
        // 让反转之后的 head 节点和后面的节点连起来
        head->next=successor;
        return listNode;//
    }
};
// @lc code=end
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* Hair=new ListNode(-1);
        Hair->next=head;

        ListNode* start=Hair;
        for(int i=0;i<left-1;i++){
            start=start->next;
        }
        ListNode* end=start->next;
        for(int j=left;j<=right;j++){
            end=end->next;
        }
        ListNode* newList=reverseList(start->next,end);
        start->next=newList;
        return Hair->next;
    }

    ListNode* reverseList(ListNode* start,ListNode* end){
        ListNode* prev=end;
        ListNode* curr=start;

        while(curr!=end){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};