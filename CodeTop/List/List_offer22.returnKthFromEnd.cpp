/*
剑指 Offer 22. 链表中倒数第k个节点
https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
[easy]
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//法一 两次反转
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* newList=reverseList(head);
        ListNode* kNode=newList;
        for (int i = 1; i < k; i++)
        {
            kNode=kNode->next;
        }
        kNode->next=nullptr;
        return reverseList(newList);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while (curr!=nullptr)
        {
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
        
    }
};
//法二 压栈法
#include<stack>
using namespace std;
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        stack<ListNode*> skNode;
        while(head!=nullptr){
            skNode.push(head);
            head=head->next;
        }
        for (int i = 1; i < k; i++)
        {
            skNode.pop();
        }
        
        return skNode.top();
    }
};

//法三 数组法 效率最低 但思想值得学习
#include<vector>
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        vector<ListNode*> nodeArr;
        while(head!=nullptr){
            nodeArr.push_back(head);
            head=head->next;
        }
        
        return nodeArr[nodeArr.size()-k];
    }
};

//法四 快慢指针 **推荐方法**
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast=head;
        ListNode* slow=head;
        for (int i = 0; i < k; i++)
        {
            fast=fast->next;
        }
        while (fast!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};