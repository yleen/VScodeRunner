/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	head := new(ListNode)
	tail := head
	add := 0

	for l1 != nil || l2 != nil || add !=0{
		if l1 != nil{
			add += l1.Val
			l1 = l1.Next
		}
		if l2 != nil{
			add += l2.Val
			l2 = l2.Next
		}
		tail.Next = new(ListNode) 
		tail.Next = &ListNode{Val: add % 10}
		add =  add / 10;
		tail = tail.Next
	}
	return head.Next
}
// @lc code=end

