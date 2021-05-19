/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
//Hash表法
# include<unordered_set>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> hashNode;
        while (head!=NULL)
        {
            if(hashNode.count(head)){
                return head;
            }
            hashNode.insert(head);
            head=head->next;
        }
        return NULL;
        
    }
};

//动态规划 快慢指针
/*
分析 设入环点为O，起点A，快慢指针相遇点为B。设AO=a,OB短为b,OB长为c。
快指针在任意时刻都比慢指针多走一倍距离，即s(fast)=2s(slow),设快指针走了n圈之后再走b长相遇，则可知：a+(b+c)n+b=a+(n+1)b+nc=2(a+b)
可得 a=(n-1)(b+c)+c，我们会发现：从相遇点到入环点的距离加上 n-1 圈的环长，恰好等于从链表头部到入环点的距离。
refer：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL&&fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                ListNode* prev=head;
                while(prev!=slow){
                    prev=prev->next;
                    slow=slow->next;
                }
                return prev;
            }
        }
        return NULL;
    }
};
// @lc code=end

