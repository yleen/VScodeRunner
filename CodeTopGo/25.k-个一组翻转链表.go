/*
 * @lc app=leetcode.cn id=25 lang=golang
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

package codetopgo

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}
	currNode := head
	kNode := head
	for i := 0; i < k; i++ {
		if kNode == nil {
			return head
		}
		kNode = kNode.Next
	}
	newList := reverseList(currNode, kNode)
	currNode.Next = reverseKGroup(kNode, k)
	return newList
}

func reverseList(start *ListNode, end *ListNode) *ListNode {
	var prev *ListNode = nil
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
