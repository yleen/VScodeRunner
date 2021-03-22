/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        return editList(head);
    }

    bool editList(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr)
        {
            slow = slow->next;
        }
        ListNode *left = head;
        ListNode *right = revertList(slow);
        while (right!=nullptr)
        {
            if (left != right)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode *revertList(ListNode *head)
    {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr)
        {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};
// @lc code=end
