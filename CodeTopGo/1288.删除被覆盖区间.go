/*
 * @lc app=leetcode.cn id=1288 lang=golang
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
func compare(a []int, b []int) bool {
	if a[0] == b[0] {
		return a[1] > b[1]
	}
	return a[0] <= b[0]
}
func removeCoveredIntervals(intervals [][]int) int {
	count := len(intervals)
	sort.Slice(intervals, func(i, j int) bool {
		if intervals[i][0] != intervals[j][0] {
			return intervals[i][0] < intervals[j][0]
		} else {
			return intervals[i][1] > intervals[j][1]
		}
	})
	end := intervals[0][1]
	for i := 1; i < len(intervals); i++ {
		if intervals[i][1] <= end {
			count--
		} else {
			end = intervals[i][1]
		}
	}
	return count
}

// @lc code=end

