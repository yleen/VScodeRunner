/*
 * @lc app=leetcode.cn id=912 lang=golang
 *
 * [912] 排序数组
 */

// @lc code=start
// bubbling
func sortArray(nums []int) []int {
	isOver := false
	for !isOver{
		isOver = true
		for i := 1; i < len(nums); i++{
			if nums[i] < nums[i - 1]{
				isOver = false
				swap(i, i - 1, nums)
			}
		}
	}
	return nums
}

//select
func sortArray(nums []int) []int {
	for i := 0; i < len(nums); i++{
		min := i
		for j := i; j < len(nums); j++{
			if nums[i] > nums[j]{
				min = j
			}
		}
		if min != i{
			swap(min, i, nums)
		}
	}
	return nums
}

//insert
func sortArray(nums []int) []int{
	for i := 0; i < len(nums); i++{
		target := nums[i]
		j = i - 1;
		for j >= 0 && nums[j] > target{
			nums[j + 1] = nums[j]
			j--
		}
		nums[j + 1] = target
	}
}

//quick
func sortArray(nums []int) []int {
	rand.Seed(time.Now().UnixNano())
	return quickSort(nums, 0, len(nums) - 1)
}

func quickSort(nums []int, start int, end int){
	if start > end{
		return nums
	}
	pivot := rand.Int() % (end - start +1) + start
	swap(pivot, end, nums)
	left := start
	right := end
	cur := nums[pivot]
	for left < right{
		for left < right && nums[left] < cur {
			left++
		}
		nums[right] = nums[left]
		for left < right && nums[right] >= cur {
			right--
		}
		nums[left] = nums[right]
	}
	nums[left] = cur
	pivot = left
	quickSort(nums, start, pivot - 1)
	quickSort(nums, pivot + 1, end)
}

//merge
func mergeSort(nums []int) []int{
	if len(nums) <= 1{
		return nums
	}
	mid := len(nums) >> 1
	left := mergeSort(nums[:mid])
	right := mergeSort(nums[mid:])
	return merge(left, right)
}

func merge(left []int, right []int) []int{
	result := make([]int, len(left) + len(right))
	l, r, i := 0, 0, 0
	for l < len(left) && r < len(right) {
		if left[l] < right[r]{
			result[i] = left[l]
			l++
		}else{
			result[i] = right[r]
			r++
		}
		i++
	}
	copy(result[i:], left[l:])
	copy(result[i + len(left) - l:], right[r:])
	return result
}

//heap
func heapSort(nums []int) []int{
	length := len(nums)
	for i := length / 2 - 1; i >= 0; i--{
		siftDownRecursive(nums, i, heapSize)
	}
	for j := length - 1; j > 0; j++{
		swap(j, 0, nums)
		siftDownRecursive(nums, 0, j)
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
	if cur != i{
		swap(cur, i, nums)
		siftDownRecursive(nums, cur, heapSize)
	}
}

func swap(a int, b int, nums []int){
	nums[a],nums[b] = nums[b],nums[a]
}
// @lc code=end

