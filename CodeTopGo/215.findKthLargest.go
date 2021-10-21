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

//大根堆
func findKthLargest(nums []int, k int) int {
	heapSize := len(nums)
	length := len(nums)
	buildMaxHeap(nums, heapSize)

	for i := length - 1; i > length - k; i--{
		swap(0, i, nums)
		heapSize--
		siftDownRecursive(nums, 0, heapSize)
	}
	return nums[0]
}

func buildMaxHeap(nums []int, heapSize int){
	length := len(nums)
	for i := length/2; i >= 0; i--{
		siftDownRecursive(nums, i, heapSize)
	}
}

func siftDownRecursive(nums []int, i int, heapSize int){
	left := i * 2 + 1
	right := i * 2 + 2
	cur := i
	if left < heapSize && nums[left] > nums[cur] {
		cur = left
	}
	if right < heapSize && nums[right] > nums[cur] {
		cur = right
	}
	if cur != i {
		swap(cur, i, nums)
		siftDownRecursive(nums, cur, heapSize)
	}

}

func swap(a int, b int, nums []int){
	nums[a],nums[b] = nums[b],nums[a]
}

// @lc code=end

