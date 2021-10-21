/*
 * @lc app=leetcode.cn id=215 lang=golang
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
//快排思想
func findKthLargest(nums []int, k int) int {
	n := len(nums)
	rand.Seed(time.Now().UnixNano())
	return quickFind(nums, 0, n - 1, n - k)	
}

func quickFind(nums []int, start int, end int, k int)int{
	pivot := rand.Int() % (end - start + 1) + start
	swap(pivot, end, nums)
	pivot = end
	if start == end && start == k {
		return nums[start]
	}
	left := start
	right := end - 1
	curr := nums[pivot]
	for left < right{
		for left < right && nums[left] < curr {
			left++
		}
		for left < right && nums[right] >= curr{
			right--
		}
		if left < right{
			swap(left, right, nums)
		}
	}
	if nums[left] < curr{
		left = end
	}
	swap(left, pivot, nums)
	pivot = left
	switch{
	case pivot == k :
		return nums[pivot]
	case pivot > k  :
		return quickFind(nums, start, pivot - 1, k)
	case pivot < k :
		return quickFind(nums, pivot + 1, end, k)
	}
	return -1
}

func swap(a int, b int, nums[]int){
	nums[a],nums[b] = nums[b],nums[a]
}
// @lc code=end

