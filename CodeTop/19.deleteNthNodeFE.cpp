/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
 * [Medium]
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* fast = head;
        ListNode* slow = hair;

        for(int i = 0; i < n; i++){
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* next = slow->next;
        slow->next = slow->next->next;
        next->next = nullptr;
        return hair->next;
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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *hair = new ListNode(0);//注意为什么要使用一个结点来指向这个链表呢 ，测试用例中具有删除后空结点的情况，若不用这个指向返回的还是单个节点head
        hair->next = head;
        ListNode *fast = head;
        ListNode *slow = hair;
        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *next = slow->next;
        slow->next = slow->next->next;
        next->next = nullptr;
        return hair->next;
    }
};