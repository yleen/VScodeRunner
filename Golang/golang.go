/**
 * Definition for singly-linked list.
 */

package C                                                                         
type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	var curr *ListNode = head
	var prev *ListNode
	for curr != nil {
		var next *ListNode = curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}

func reverseListRecur(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var newHead = reverseList(head.Next)
	head.Next.Next = head
	head.Next = nil

	return newHead
}
