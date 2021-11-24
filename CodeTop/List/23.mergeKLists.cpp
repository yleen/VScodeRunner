/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
#include<vector>
#include<queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//法1 依次合并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newList = nullptr;
        int n = lists.size();
        for(int i = 0; i < n; i++){
            newList = mergeTwoList(newList, lists[i]);
        }
        return newList;
    }

    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* newList = new ListNode(0);
        ListNode* head = newList;
        while (list1 && list2)
        {
            if(list1->val > list2->val){
                newList->next = list2;
                list2 = list2->next;
            }else{
                newList->next = list1;
                list1 = list1->next;
            }
            newList = newList->next;
        }
        // newList->next = list1 ? list1 : list2;
        if(list1){
            newList->next = list1;
        } 
        if(list2){
            newList->next = list2;
        }
        return head->next;
    }
};

//法二 分治法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size() - 1);
    }
    ListNode* merge(vector<ListNode*>& lists, int left, int right){
        if(left == right){
            return lists[left];
        }
        if(left > right){
            return nullptr;
        }
        int mid = (left + right) >> 1;
        return mergeTwoList(merge(lists, left, mid), merge(lists, mid + 1, right));
    }

    ListNode* mergeTwoList(ListNode* list1, ListNode* list2){
        ListNode* newList = new ListNode(0);
        ListNode* head = newList;
        while (list1 && list2)
        {
            if(list1->val > list2->val){
                newList->next = list2;
                list2 = list2->next;
            }else{
                newList->next = list1;
                list1 = list1->next;
            }
            newList = newList->next;
        }
        // newList->next = list1 ? list1 : list2;
        if(list1){
            newList->next = list1;
        } 
        if(list2){
            newList->next = list2;
        }
        return head->next;
    }
};

//法三 堆 此方法好像比优先队列快？
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newList = new ListNode(0);
        ListNode* head = newList;
        int heapSize = lists.size();
        if(heapSize == 0){
            return nullptr;
        }
        for(int i = 0; i < heapSize;){
            if(lists[i] == nullptr){
                swap(lists[i], lists[heapSize - 1]);
                heapSize--;
                lists.pop_back();
            }else{
                i++;
            }
        }
        buildMinHeap(lists, heapSize);
        while(heapSize > 0){
            head->next = lists[0];
            head = head->next;
            lists[0] = lists[0]->next;
            if(!lists[0]){
                heapSize--;
                swap(lists[0],lists[heapSize]);
            }
            SiftDownRecursive(lists, 0, heapSize);
        }
        return newList->next;
    }

    void buildMinHeap(vector<ListNode*>& lists, int heapSize){
        int length = lists.size();
        for(int i = length / 2; i >= 0; i--){
            if(lists[i]){
                SiftDownRecursive(lists, i, heapSize);
            }
        }
    }

    void SiftDownRecursive(vector<ListNode*>& lists, int i, int heapSize){
        int left = i * 2 + 1;
        int right = i * 2 + 2;
        int cur = i;
        if(left < heapSize && lists[cur]->val > lists[left]->val){
            cur = left;
        }
        if(right < heapSize && lists[cur]->val > lists[right]->val){
            cur = right;
        }
        if(cur != i){
            swap(lists[cur], lists[i]);
            SiftDownRecursive(lists, cur, heapSize);
        }
    }
};
//法四 优先队列

class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
// @lc code=end