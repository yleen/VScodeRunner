/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
func search(nums []int, target int) int {
	n := len(nums)
	if n == 0 {
		return -1
	}
	if n == 1{
		if nums[0] == target{
			return 0
		}
		return -1
	}
	left := 0
	right := n - 1


	for left <= right {
		mid := (right - left) / 2 + left
		if nums[mid] == target {
			return mid
		}
		if nums[0] <= nums[mid]{
			if nums[mid] > target && nums[0] <= target{
				right = mid - 1
			}else{
				left = mid + 1
			}
		}else{
			if nums[mid] < target && target <= nums[n - 1]{
				left = mid + 1
			}else{
				right = mid - 1
			}
		}
	}
	return -1
}
// @lc code=end

