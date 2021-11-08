/*
 * @lc app=leetcode.cn id=46 lang=golang
 *
 * [46] 全排列
 */

// @lc code=start
var allPossible [][]int
func permute(nums []int) [][]int{
	allPossible = [][]int{}
	backPermute(nums, 0)
	return allPossible
}

func backPermute(nums []int, first int){
	if first == len(nums){
		curr := make([]int, len(nums))
		copy(curr, nums)
		allPossible = append(allPossible, curr)
		// allPossible = append(allPossible, nums) 之前是这样写，但是最后的 数组都是一样的， 原因为直接这样赋值 allPossible 存储的是nums的地址，当nums变化时 allPossible中的数组也跟着变化。
	}
	for i := first; i < len(nums); i++{
		swap(nums, first, i)
		backPermute(nums, first + 1)
		swap(nums, first, i)
	}
}
func swap(nums []int, a int, b int){
	nums[a], nums[b] = nums[b], nums[a]
}

// var res [][]int
// func permute(nums []int) [][]int {
// 	res = [][]int{}
// 	backTrack(nums,len(nums),[]int{})
// 	return res
// }
// func backTrack(nums []int,numsLen int,path []int)  {
// 	if len(nums)==0{
// 		p:=make([]int,len(path))
// 		copy(p,path)
// 		res = append(res,p)
// 	}
// 	for i:=0;i<numsLen;i++{
// 		cur:=nums[i]
// 		path = append(path,cur)
// 		nums = append(nums[:i],nums[i+1:]...)//直接使用切片
// 		backTrack(nums,len(nums),path)
// 		nums = append(nums[:i],append([]int{cur},nums[i:]...)...)//回溯的时候切片也要复原，元素位置不能变
// 		path = path[:len(path)-1]

// 	}
// }

// @lc code=end

