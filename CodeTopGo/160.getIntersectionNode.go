/*
 * @lc app=leetcode.cn id=160 lang=golang
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	top := headA
	under := headB
    for top != under{
		if top == nil{
			top = headB
		}else{
			top = top.Next
		}
		if under == nil{
			under = headA
		}else{
			under = under.Next
		}
	}
	return top;
}
// @lc code=end

