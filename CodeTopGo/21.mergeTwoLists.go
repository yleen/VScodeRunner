/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{}
	newList := head
	for l1 != nil && l2 != nil{
		if l1.Val > l2.Val{
			newList.Next = l2
			l2 = l2.Next
		}else{
			newList.Next = l1
			l1 = l1.Next
		}
		newList = newList.Next
	}
	if l1 != nil{
		newList.Next = l1
	}
	if l2 != nil{
		newList.Next = l2
	}
	return head.Next
}
// @lc code=end

