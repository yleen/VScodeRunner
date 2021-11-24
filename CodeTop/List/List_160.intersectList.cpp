/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * [easy]
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
A和B两个链表长度可能不同，但是A+B和B+A的长度是相同的，
所以遍历A+B和遍历B+A一定是同时结束。 如果A,B相交的话A和B有一段尾巴是相同的，
所以两个遍历的指针一定会同时到达交点 如果A,B不相交的话两个指针就会同时到达A+B（B+A）的尾节点
*/
#include <iostream>

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *top=headA;
        ListNode *under=headB;
        while (top!=under)
        {
            top=top==nullptr?headB:top->next;//注意是top 而不是top->next 因为要是next就是死循环了
            under=under==nullptr?headA:under->next;
        }
        
        return top;
        
    }
};
// @lc code=end
