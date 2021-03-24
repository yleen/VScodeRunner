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
