/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * [medium]
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
# define NULL 0

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
# include<unordered_set>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    }
};
// @lc code=end

