/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 * https://leetcode-cn.com/problems/palindrome-linked-list/
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
#include<stack>
using namespace std;
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
            slow = slow->next;//如果链表结点是奇数  需要移动到后半部分来逆转  如 1->2->3->4->5   需要逆转45 而不是345
        }
        ListNode *left = head;
        ListNode *right = revertList(slow);
        while (right!=nullptr)//注意此处判定条件
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


//法二 用栈  思路尚可  但是比较耗时
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> skList;
        ListNode* tmp=head;
        int count=0;
        while(tmp!=nullptr){
            skList.push(tmp->val);
            tmp=tmp->next;
            count++;
        }

        ListNode* tmp2=head;
        for(int i=0;i<count/2;i++){
            if(tmp2->val!=skList.top()){
                return false;
            }
            tmp2=tmp2->next;
            skList.pop();
        }
        return true;
    }
};
// @lc code=end
