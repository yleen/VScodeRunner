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
	first := hair
	second := head
	for i := 0; i < left-1; i++ {
		first = first.Next
	}
	second = first.Next
	for j := left; j <= right; j++ {
		second = second.Next
	}

	first.Next = reverseList(first.Next, second)
	return hair.Next
}

func reverseList(start *ListNode, end *ListNode) *ListNode {
	prev := end
	curr := start
	for curr != end {
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}

// @lc code=end

