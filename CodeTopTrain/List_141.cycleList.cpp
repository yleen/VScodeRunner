/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 * https://leetcode-cn.com/problems/linked-list-cycle/
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
#define NULL
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#include<unordered_set>
using namespace std;
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        
    }
};
// @lc code=end
