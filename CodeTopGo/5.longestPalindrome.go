/*
 * @lc app=leetcode.cn id=5 lang=golang
 *
 * [5] 最长回文子串 //TODO
 */

// @lc code=start
func longestPalindrome(s string) string {
	maxStr := ""
	uniqueChar := make(map[string]string)
	left := 0
	right := len(s) - 1
	for left <= right{
		if val,ok := uniqueChar[s[i]]; ok{
			delete(uniqueChar, s[left])
			left++
		}
	}
}
func longestPalindrome(s string) string {
	n := len(s)
	if n == 1 {
		return s
	}
	start, end := 0, 0
	for i := 0; i < n; {
		l, r := i, i
		//如果字符串相同则分别冲前一个和后一个开始回文
		for r < n-1 && s[r] == s[r+1] {
			r++
		}
		i = r + 1
		for l > 0 && r < n-1 && s[l-1] == s[r+1] {
			l--
			r++
		}
		if end < r-l {
			start = l
			end = r - l
		}
	}
	return s[start : start+end+1]
}

// @lc code=end

