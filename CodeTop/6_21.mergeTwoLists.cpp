/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
*/
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

//迭代
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* retList=new ListNode(-1);//这里注意 是把返回值设置-1
        ListNode* head=retList;
        while (l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val<l2->val){
                head->next=l1;
                l1=l1->next;
            }else
            {
                head->next=l2;
                l2=l2->next;
            }
            head=head->next;
        }
        if(l1!=nullptr) head->next=l1;
        if(l2!=nullptr) head->next=l2;
        return retList->next;
    }
};

//TODO 递归