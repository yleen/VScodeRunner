/*
 * @lc app=leetcode.cn id=15 lang=golang
 *
 * [15] 三数之和
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	sumList := make([][]int,0)
	sort.Ints(nums)
	length := len(nums)
	for i := 0; i < length; i++{
		first := i
		if nums[first] > 0 {
			break
		}
		if first > 0 && nums[first] == nums[first - 1] {
			continue
		}
		target := -nums[first]
		third := length - 1
		for second := first + 1; second < length; second++{
			if second > first + 1 && nums[second] == nums[second - 1]{
				continue
			}
			for second < third && nums[second] + nums[third] > target{
				third--
			}
			if second == third{
				break
			}
			if nums[second] + nums[third] == target{
				sumList = append(sumList,[]int{nums[first],nums[second],nums[third]})
			}
		}
	}

	return sumList
}
// @lc code=end

