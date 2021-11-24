/*
 * @lc app=leetcode.cn id=236 lang=golang
 *
 * [236] 二叉树的最近公共祖先
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
//  var father = make(map[int]*TreeNode) //问题 把key改为int 为什么过不去测试用例？

//  var visit = make(map[int]bool)
//  func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
// 	father[root.Val] = nil
// 	dfs(root)
// 	for p != nil{
// 		visit[p.Val] = true
// 		p = father[p.Val]
// 	}
// 	for q != nil{
// 		if visit[q.Val]{
// 			return q
// 		}
// 		q = father[q.Val]
// 	}
// 	return nil
// }

// func dfs(root *TreeNode){
// 	if root.Left != nil{
// 		father[root.Left.Val] = root
// 		dfs(root.Left)
// 	}
// 	if root.Right != nil{
// 		father[root.Right.Val] = root
// 		dfs(root.Right)
// 	}
// }

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	 if root == nil{
		 return nil
	 }
	 if root == p || root == q{
		 return root
	 }

	 left := lowestCommonAncestor(root.Left, p, q)
	 right := lowestCommonAncestor(root.Right, p, q)
	 if left != nil && right != nil{
		 return root
	 }
	 if left != nil{
		 return left
	 }
	 if right != nil{
		 return right
	 }
	 return nil
}
// func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
//     if root == nil {
//         return nil
//     }
//     if root.Val == p.Val || root.Val == q.Val {
//         return root
//     }
//     left := lowestCommonAncestor(root.Left, p, q)
//     right := lowestCommonAncestor(root.Right, p, q)
//     if left != nil && right != nil {
//         return root
//     }
//     if left == nil {
//         return right
//     }
//     return left
// }

// @lc code=end

