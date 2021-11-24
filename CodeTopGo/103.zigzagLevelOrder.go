/*
 * @lc app=leetcode.cn id=103 lang=golang
 *
 * [103] 二叉树的锯齿形层序遍历
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
func zigzagLevelOrder(root *TreeNode)(treeArr [][]int){
	if root == nil {
		return treeArr
	}
	qTree := []*TreeNode{root}
	isLeft := true
	for i := 0; len(qTree) > 0; i++{
		levelQ := qTree
		qTree = nil
		vals := []int{}
		for _, node := range levelQ {
			vals = append(vals, node.Val)
			if node.Left != nil{
				qTree = append(qTree, node.Left)
			}
			if node.Right != nil{
				qTree = append(qTree, node.Right)
			}
		}
		if !isLeft{
			vals = reverse(vals)
		}
		treeArr = append(treeArr, vals)
		isLeft = !isLeft
	}
	return treeArr
}
func reverse(s []int) []int {
    for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
        s[i], s[j] = s[j], s[i]
    }
    return s
}
// @lc code=end

