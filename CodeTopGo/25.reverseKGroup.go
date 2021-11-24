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
// func reverseKGroup(head *ListNode, k int) *ListNode {
// 	kNode := head
// 	curr := head
// 	for i := 0; i < k; i++{
// 		if kNode == nil{
// 			return head
// 		}
// 		kNode = kNode.Next
// 	}
// 	newList := reverseList(curr, kNode)
// 	curr.Next = reverseKGroup(kNode, k)
// 	return newList
// }



func reverseKGroup(head *ListNode, k int) *ListNode{

	hair := &ListNode{Next:head}
	kNode := hair
	prev := hair
	for kNode.Next != nil{
		for i := 0; i < k && kNode != nil; i++{
			kNode = kNode.Next
			if kNode == nil{
				return hair.Next
			}
		}
		next := kNode.Next
		start := prev.Next
		kNode.Next = nil
		prev.Next = reverseList(start,nil)
		start.Next = next
		prev = start
		kNode = prev
	}
	return hair.Next
}

func reverseList(head *ListNode, end *ListNode) *ListNode{
	var prev *ListNode
	curr := head
	for curr != end{
		next := curr.Next
		curr.Next = prev
		prev = curr
		curr = next
	}
	return prev
}
// @lc code=end

