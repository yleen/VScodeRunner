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
#include <functional>
using namespace std;
//法一 递归
class Solution
{
public:
    ListNode *reverseKGroupRecur(ListNode *head, int k)
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
        currNode->next = reverseKGroupRecur(kNode, k);
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

//法二 迭代法
class Solution2 {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }

        ListNode* hair=new ListNode(0);
        ListNode* prev=hair;
        hair->next=head;
        while(head!=nullptr){
            ListNode* kNode=prev;
            for(int i=0;i<k;i++){
                kNode=kNode->next;
                if(kNode==nullptr){
                    return hair->next;
                }
            }
            ListNode* next=kNode->next;
            tie(head,kNode)=revertList(head,kNode);
            prev->next=head;
            kNode->next=next;
            prev=kNode;
            head=kNode->next;
        }
        return hair->next;
    }


     pair<ListNode*, ListNode*> revertList(ListNode* first,ListNode* end){
        ListNode* prev=end->next;//注意此处
        ListNode* curr=first;
        while(prev!=end){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return {end,first};
    }
};