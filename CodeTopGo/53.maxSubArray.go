/*
 * @lc app=leetcode.cn id=53 lang=golang
 *
 * [53] 最大子序和
 */

// @lc code=start
func maxSubArray(nums []int) int {
	maxSub := nums[0]
	currSub := 0
	for _,v := range nums{
		currSub = maxNum(v + currSub,v)
		maxSub = maxNum(currSub, maxSub)
	}
	return maxSub
}

func maxNum(a int, b int) int{
	if a > b{
		return a
	}else{
		return b
	}
}

// @lc code=end

