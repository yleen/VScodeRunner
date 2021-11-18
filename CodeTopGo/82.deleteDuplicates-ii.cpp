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
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
// #include<unordered_map>
// using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // unordered_map<int, ListNode*> noSame;
        ListNode* searchNode = new ListNode(0);
        ListNode* newHead = searchNode;
        searchNode->next = head;
        while (searchNode->next != nullptr && searchNode->next->next != nullptr)
        {
            if(searchNode->next->val == searchNode->next->next->val){
                int sameVal = searchNode->next->val;
                // searchNode = noSame[sameVal];
                // noSame.erase(sameVal);
                while(searchNode->next != nullptr && searchNode->next->val == sameVal){
                    ListNode* next = searchNode->next;
                    searchNode->next = searchNode->next->next;
                    // next->next = nullptr;
                    // delete next;
                }
                // ListNode* sameNode = sameNodePre->next;
                // sameNodePre->next = sameNodePre->next->next;
                // sameNode->next = nullptr;
                // delete sameNode;
            }else{
                // noSame[searchNode->next->val] = searchNode;
                searchNode = searchNode->next;
            }
        }
        return newHead->next;
    }
};
// @lc code=end

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (!head) {
//             return head;
//         }
        
//         ListNode* dummy = new ListNode(0, head);

//         ListNode* cur = dummy;
//         while (cur->next && cur->next->next) {
//             if (cur->next->val == cur->next->next->val) {
//                 int x = cur->next->val;
//                 while (cur->next && cur->next->val == x) {
//                     cur->next = cur->next->next;
//                 }
//             }
//             else {
//                 cur = cur->next;
//             }
//         }

//         return dummy->next;
//     }
// };