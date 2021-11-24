/*
 * @lc app=leetcode.cn id=92 lang=golang
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseBetween(head *ListNode, left int, right int) *ListNode {
	hair := &ListNode{}
	hair.Next = head
	start := hair
	for i := 0; i < left - 1; i++{
		start = start.Next
	}
	end := start.Next
	for j := left; j <= right; j++{
		end = end.Next
	}
	next := reverse(start.Next, end)
	start.Next = next
	return hair.Next
}

func reverse(start *ListNode, end *ListNode)*ListNode{
	cur := start
	pre := end
	for cur != end{
		next := cur.Next
		cur.Next = pre
		pre = cur
		cur = next
	}
	return pre
}
// @lc code=end

