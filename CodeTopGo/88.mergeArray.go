/*
 * @lc app=leetcode.cn id=88 lang=golang
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
func merge(nums1 []int, m int, nums2 []int, n int)  {
	count := m + n - 1
	m = m - 1
	n = n - 1
	for count >= 0 {
		if m >= 0 && n >= 0{
			if nums1[m] > nums2[n]{
				nums1[count] = nums1[m]
				m--
			}else{
				nums1[count] = nums2[n]
				n--
			}
		}else{
			if m >= 0{
				nums1[count] = nums1[m]
				m--
			}else{
				nums1[count] = nums2[n]
				n--
			}
		}
		count--
	}
}

// @lc code=end

