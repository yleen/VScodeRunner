/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 //迭代
func reverseList(head *ListNode) *ListNode {
	var pre *ListNode = nil
	var cur *ListNode = head
	for cur != nil {
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
//递归
func reverseList(head *ListNode) *ListNode {
	if head ==nil || head.Next == nil {
		return head
	}
	newList := reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil
	return newList
}
//https://labuladong.github.io/algo/2/15/15/
// @lc code=end

