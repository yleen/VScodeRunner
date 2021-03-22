/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == nullptr)
            return head;
        ListNode *currNode = head;
        ListNode *kNode = head;
        for (int i = 0; i < k; i++)
        {
            if (kNode == nullptr)
                return head;
            kNode = kNode->next;
        }

        ListNode *newList = reverseList(currNode, kNode);
        currNode->next = reverseKGroup(kNode, k);
        return newList;
    }

    ListNode *reverseList(ListNode *first, ListNode *end)
    {
        ListNode *prevNode = nullptr;
        ListNode *currNode = first;
        while (currNode != end)
        {
            ListNode *tmp = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = tmp;
        }
        return prevNode;
    }
};
// @lc code=end
//参考：https://labuladong.gitbook.io/algo/shu-ju-jie-gou-xi-lie/shou-ba-shou-shua-lian-biao-ti-mu-xun-lian-di-gui-si-wei/k-ge-yi-zu-fan-zhuan-lian-biao