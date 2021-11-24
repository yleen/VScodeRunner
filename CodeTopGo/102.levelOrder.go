/*
 * @lc app=leetcode.cn id=102 lang=golang
 *
 * [102] 二叉树的层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //这个方法太妙了 
func levelOrder(root *TreeNode)(treeArr [][]int) {
	if root == nil {
		return treeArr
	}
	qTree := []*TreeNode{root}
	for i := 0; len(qTree) > 0; i++{// 注意条件为len（qTree）> 0
		levelQ := qTree
		qTree = nil
		vals := []int{}
		for _, node := range levelQ{
			vals = append(vals, node.Val)
			if node.Left != nil{
				qTree = append(qTree, node.Left)
			}
			if node.Right != nil{
				qTree = append(qTree, node.Right)
			}
		}
		treeArr = append(treeArr, vals)
	}
	return treeArr
}

// @lc code=end

