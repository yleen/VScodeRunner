/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	strMap := map[byte]int{}
	n := len(s)
	left := 0
	res := 0
	for i := 0; i < n; i++ {
		for strMap[s[i]] != 0 {
			delete(strMap, s[left])
			left++
		}
		strMap[s[i]]++
		res = max(res, i-left+1)
	}
	return res
}

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

// @lc code=end

