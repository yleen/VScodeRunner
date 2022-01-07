/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
#include<unordered_map>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* searchNode = new ListNode(0);
        ListNode* newHead = searchNode;
        searchNode->next = head;
        while (searchNode->next != nullptr && searchNode->next->next != nullptr)
        {
            if(searchNode->next->val == searchNode->next->next->val){
                int sameVal = searchNode->next->val;
                while(searchNode->next != nullptr && searchNode->next->val == sameVal){
                    ListNode* next = searchNode->next;
                    searchNode->next = searchNode->next->next;
                    //应该把netxt删掉
                }
            }else{
                searchNode = searchNode->next;
            }
        }
        return newHead->next;
    }
};
// @lc code=end