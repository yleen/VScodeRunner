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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            return reverseList(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }

    ListNode* successor = nullptr;
    ListNode* reverseList(ListNode* head,int index){
        if(index == 1){
            successor = head->next;
            return head;
        }
        ListNode* newList = reverseList(head->next,index - 1);
        head->next->next = head;
        head->next = successor;
        return newList;
    }
};
// @lc code=end


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//递归
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
//迭代
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* hair=new ListNode(-1);
        hair->next=head;
        ListNode* start = Hair;
        ListNode* end = head;
        for(int i = 0; i < left - 1; i++){
            start = start->next;
            end = end->next;
        }
        for(int j = left; j <= right; j++){
            end = end->next;
        }
        start->next = reverseList(start->next,end);
        return hair->next;
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