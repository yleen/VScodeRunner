/*
 * @lc app=leetcode.cn id=1 lang=golang
 *
 * [1] 两数之和
 */

// @lc code=start
// 暴力解法
func twoSum(nums []int, target int) []int {
	for i,_ := range nums{
		for j := i+1;j < len(nums);j++{
			if nums[i] + nums[j] == target{
				return []int {i,j}
			}
		}
	}
    return nil
}
//hash
func twoSum(nums []int, target int) []int {
	hashTable := make(map[int]int)
	for i,v := range nums {
		a := v
		b := target -a
		if va,ok := m[b]; ok{
			return []int {i,va}
		}
		hashTable[a] = i
	}
	return nil
}
// @lc code=end

