/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast-> next!= nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = slow->next;
        slow->next = nullptr;
        ListNode* left = head;
        right = reverseList(right);

        //这种合并方法 可以输出正确结果
        ListNode* temp1 = NULL;
		while(right != nullptr)
		{
			temp1 = right->next;
			right->next = left->next;
			left->next = right;
			left = left->next->next;
			right = temp1;
		}

        //这种合并输出错误 是为什么
        // ListNode* newList = new ListNode(0);
        // ListNode* newHead = newList;
        // while (right != nullptr)
        // {
        //     newHead->next = left;
        //     newHead = newHead->next;
        //     newHead->next = right;
        //     newHead = newHead->next;
        //     left = left->next;
        //     right = right->next;
        // }
        // newHead->next = nullptr;
        // head->next = nullptr;
        // head->next = newList->next;
    }
    ListNode* reverseList(ListNode* start){
        ListNode* pre = nullptr;
        ListNode* cur = start;
        while (cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end
