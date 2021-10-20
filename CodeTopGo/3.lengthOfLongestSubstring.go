/*
 * @lc app=leetcode.cn id=3 lang=golang
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
func lengthOfLongestSubstring(s string) int {
	 hashTable := make(map[byte]int)
	 left := 0
	 maxLen := 0
	 n := len(s)
	 for i := 0;i < n;i++{
		 for hashTable[s[i]] != 0 {
			delete(hashTable,s[left])
			left++
		 }
		 hashTable[s[i]]++
		 maxLen = max(maxLen,i - left + 1)
	 }
	 return maxLen
}

func max(a int,b int) int{
	if a > b{
		return a
	}else{
		return b
	}
}
// @lc code=end

