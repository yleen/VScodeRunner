/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * [medium]
 * https://leetcode-cn.com/problems/add-two-numbers/
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

class solution
{
public:
    listnode *addtwonumbers(listnode *l1, listnode *l2)
    {

    }
};
// @lc code=end
struct listnode
{
    int val;
    listnode *next;
    listnode() : val(0), next(nullptr) {}
    listnode(int x) : val(x), next(nullptr) {}
    listnode(int x, listnode *next) : val(x), next(next) {}
};
#pragma region
class solution
{
public:
    listnode *addtwonumbers(listnode *l1, listnode *l2)
    {
        listnode* sumlist = new listnode(0);
        listnode* head = sumlist;
        int add = 0;
        while (l1 != nullptr || l2 != nullptr || add != 0)
        {
            if(l1 != nullptr){
                add += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                add += l2->val;
                l2 = l2->next;
            }
            sumlist->next = new listnode(add % 10);
            add = add / 10;
            sumlist = sumlist->next;
        }
        return head->next;
    }
};
#pragma endregion