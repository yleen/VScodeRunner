/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * https://leetcode-cn.com/problems/reverse-linked-list/
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

//迭代法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *curr = head;//用curr代替head是为了不破坏原链表结构
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

//递归
class Solution
{
public:
    ListNode *reverseListRecur(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* newhead=reverseListRecur(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }
};


// @lc code=end

